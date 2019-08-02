using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GinHomingAndShooting : MonoBehaviour
{
    //Used for homing mechanics of GIN object, copied from Pixie more or less
    public GameObject playerGIN;
    public Transform playerTargetGIN;
    public Rigidbody GINRigidbody;
    public float turnGIN;
    public float GINVelocity;

    //Used for firing GINRays
    public Rigidbody ginRay;
    public Transform ginPos;
    public float ginForce = 2000;
    public GameObject playerCamGIN;
    public float ginDistance = 20f;
    public float fireRateGIN = 2f;
    private float nextFireGIN = 1f;

    public void Start()
    {

        //Used for homing mechanics of GIN object, copied from Pixie more or less
        playerGIN = GameObject.FindWithTag("Player");
        playerTargetGIN = playerGIN.transform;
        turnGIN = 10f;
        GINVelocity = 7f;

        //Used for firing GINRays
        playerCamGIN = GameObject.FindWithTag("MainCamera");
    }

    public void Update()
    {
        //Used for firing GINRays
        ginShoot();
    }

    public void FixedUpdate()
    {
        //Used for homing mechanics of GIN object, copied from Pixie more or less
        if (Vector3.Distance(transform.position, playerTargetGIN.transform.position) < ginDistance)
        {
            GINRigidbody.velocity = transform.forward * GINVelocity;
            Quaternion playerTargetRotationGIN = Quaternion.LookRotation(playerTargetGIN.position - transform.position);
            GINRigidbody.MoveRotation(Quaternion.RotateTowards(transform.rotation, playerTargetRotationGIN, turnGIN));
        }
    }

    public void ginShoot()
    {
        //Used for firing GINRays
        if (Vector3.Distance(transform.position, playerCamGIN.transform.position) <= ginDistance && Time.time > nextFireGIN)
        {
            nextFireGIN = Time.time + fireRateGIN; //used for delay in firing
            Rigidbody ray = Instantiate(ginRay, ginPos.position, ginPos.rotation) as Rigidbody;
            ray.AddForce(ginPos.forward * ginForce);
        }

    }

}
