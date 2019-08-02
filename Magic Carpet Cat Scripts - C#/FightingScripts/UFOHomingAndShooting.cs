using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UFOHomingAndShooting : MonoBehaviour
{
    //Used for homing mechanics of UFO object, copied from Pixie more or less
    public GameObject playerUFO;
    public Transform playerTargetUFO;
    public Rigidbody UFORigidbody;
    public float turnUFO;
    public float UFOVelocity;

    //Used for firing UFORays
    public Rigidbody ufoRay;
    public Transform ufoPos;
    public float ufoForce = 30;
    public GameObject playerCamUFO;
    public float ufoDistance = 30f;
    public float fireRateUFO = 2f;
    private float nextFireUFO = 1f;

    public void Start()
    {

       //Used for homing mechanics of UFO object, copied from Pixie more or less
        playerUFO = GameObject.FindWithTag("Player");
        playerTargetUFO = playerUFO.transform;
        turnUFO = 5f;
        UFOVelocity = 3f;

        //Used for firing UFORays
        playerCamUFO = GameObject.FindWithTag("MainCamera");
    }

    public void Update()
    {
        //Used for firing UFORays
        ufoShoot();
    }

    public void FixedUpdate()
    {
            //Used for homing mechanics of UFO object, copied from Pixie more or less
        if (Vector3.Distance(transform.position, playerTargetUFO.transform.position) < ufoDistance)
        {
            UFORigidbody.velocity = transform.forward * UFOVelocity;
            Quaternion playerTargetRotationUFO = Quaternion.LookRotation(playerTargetUFO.position - transform.position);
            UFORigidbody.MoveRotation(Quaternion.RotateTowards(transform.rotation, playerTargetRotationUFO, turnUFO));
        }
    }

    public void ufoShoot()
    {
        //Used for firing UFORays
        if (Vector3.Distance(transform.position, playerCamUFO.transform.position) <= ufoDistance && Time.time > nextFireUFO)
        {
            nextFireUFO = Time.time + fireRateUFO; //used for delay in firing
            Rigidbody ray = Instantiate(ufoRay, ufoPos.position, ufoPos.rotation) as Rigidbody;
            ray.AddForce(ufoPos.forward * ufoForce);
        }

    }

}
