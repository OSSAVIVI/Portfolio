using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class JackOLanternShooter : MonoBehaviour
{

    //Used for firing UFORays
    public Rigidbody flame;
    public Transform flamePos;
    public float flameForce = 2000;
    public GameObject playerCam;
    public float distance = 20f;
    public float fireRate = 2f;
    private float nextFire = 1f;

    public void Start()
    {
        //Used for firing UFORays
        playerCam = GameObject.FindWithTag("MainCamera");
    }

    public void Update()
    {
        //Used for firing UFORays
        jackShoot();
    }


    public void jackShoot()
    {
        //Used for firing UFORays
        if (Vector3.Distance(transform.position, playerCam.transform.position) <= distance && Time.time > nextFire)
        {
            nextFire = Time.time + fireRate; //used for delay in firing
            Rigidbody fire = Instantiate(flame, flamePos.position, flamePos.rotation) as Rigidbody;
            fire.AddForce(flamePos.forward * flameForce);
        }

    }
}

