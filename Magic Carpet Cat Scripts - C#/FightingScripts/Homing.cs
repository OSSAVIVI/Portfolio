using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Homing : MonoBehaviour
{
    public GameObject player;
    public Transform playerTarget;
    public Rigidbody pixieRigidBody;

    public float turn;
    public float pixieVelocity;

    public void Start()
    {
        player = GameObject.FindWithTag("Player");
        playerTarget = player.transform;

        turn = 10f;
        pixieVelocity = 7f;
    }

    public void FixedUpdate()
    {

        if (Vector3.Distance(transform.position, playerTarget.transform.position) < 10)
        {
            pixieRigidBody.velocity = transform.forward * pixieVelocity;

            Quaternion playerTargetRotation = Quaternion.LookRotation(playerTarget.position - transform.position);

            pixieRigidBody.MoveRotation(Quaternion.RotateTowards(transform.rotation, playerTargetRotation, turn));
        }
    }
       
}
