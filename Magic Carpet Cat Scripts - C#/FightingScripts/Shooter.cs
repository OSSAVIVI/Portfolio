using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shooter : MonoBehaviour
{
    public Rigidbody projectile;
    public Transform shotPos;
    public float shotForce = 1000f;
    //public float moveSpeed = 10f;


    public Rigidbody bomb;
    public Transform bombPos;
    public float bombForce = 1000f;

    //used for delay in firing rainbows
    public float fireRate = 0.5f;
    private float nextFire = 1f;

    public float fireRateBomb = 0.5f;
    private float nextFireBomb = 1f;

    void Update()
    {   //commented out because fucked with camera
        //float h = Input.GetAxis("Horizontal") * Time.deltaTime * moveSpeed;
        //float v = Input.GetAxis("Vertical") * Time.deltaTime * moveSpeed;
        // transform.Translate(new Vector3(h, v, 0));

        if (Input.GetButtonUp("Fire1") && Time.time > nextFire)
        {
            nextFire = Time.time + fireRate; //used for delay in firing
            Rigidbody shot = Instantiate(projectile, shotPos.position, shotPos.rotation) as Rigidbody;
            shot.AddForce(shotPos.forward * shotForce);
        }

        if (Input.GetButtonUp("Fire2") && Time.time > nextFireBomb)
        {
            nextFireBomb = Time.time + fireRateBomb; //used for delay in firing
            Rigidbody bombLoad = Instantiate(bomb, bombPos.position, bombPos.rotation) as Rigidbody;
            bombLoad.AddForce(shotPos.forward * bombForce);
        }
    }
}
