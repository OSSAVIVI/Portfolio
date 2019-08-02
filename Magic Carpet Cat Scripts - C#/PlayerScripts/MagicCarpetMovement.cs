using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MagicCarpetMovement : MonoBehaviour
{
    public float moveSpeed;
    public float rotSpeed;
    public float rotX;
    public float rotY;
    public float rotZ;
    public bool antiGravity;
    public bool speedMode;
    public Rigidbody rb;
    public Camera mainCamera;
    //public ParticleSystem ps; will be used for changing particle colors in speedmode

    // Start is called before the first frame update
    void Start()
    {
        print("Magic Carpet Test is Running...");
        moveSpeed = 10f;
        antiGravity = false;
        rb = GetComponent<Rigidbody>();
        //ps = GetComponent<ParticleSystem>(); will be used for changing particle colors in speedmode
        rotSpeed = 200f;
        speedMode = false;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        //Used to move character 
        transform.Translate(moveSpeed*Input.GetAxis("Horizontal")*Time.deltaTime, moveSpeed*Input.GetAxis("Jump")*Time.deltaTime, moveSpeed*Input.GetAxis("Vertical")*Time.deltaTime);

        //Ends game if player goes out of bounds
        if (rb.position.y < -15f || rb.position.y > 150f ||rb.position.x < -150 || rb.position.x > 150 || rb.position.z < -150 || rb.position.z > 150)
        {
            FindObjectOfType<GameManager>().EndGame();
        }
    }

    private void Update()
    {//Used to rotate character and look around
        rotX -= Input.GetAxis("Mouse Y") * Time.deltaTime * rotSpeed;
        rotY += Input.GetAxis("Mouse X") * Time.deltaTime * rotSpeed;

        //prevents the camera from turning up and down too much
        if (rotX < -80)
        {
            rotX = -80;
        }
        else if(rotX > 10)
        {
            rotX = 10;
        }

        transform.rotation = Quaternion.Euler(0, rotY, 0);
        GameObject.FindWithTag("MainCamera").transform.rotation = Quaternion.Euler(rotX, rotY, 0);

        //Used to turn speed mode on and off with "Q"
        if (Input.GetKeyUp(KeyCode.Q) && speedMode == false)
        {
            speedMode = true;
            moveSpeed = 30f;
        }
        else if (Input.GetKeyUp(KeyCode.Q) && speedMode == true)
        {
            speedMode = false;
            moveSpeed = 10f;
        }

        //Used to turn gravity on and off with "E"
        if (Input.GetKeyUp(KeyCode.E) && antiGravity == false)
        {
            antiGravity = true;
            rb.GetComponent<Rigidbody>().useGravity = false;
        }
        else if (Input.GetKeyUp(KeyCode.E) && antiGravity == true)
        {
            antiGravity = false;
            rb.GetComponent<Rigidbody>().useGravity = true;
        }
    }
}
