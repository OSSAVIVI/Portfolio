using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpinAroundZAxis : MonoBehaviour
{
    void Update()
    {
        //Spin around local Z axis
        transform.RotateAround(transform.position, transform.forward, Time.deltaTime * 90f);
    }
}
