using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpinAroundYAxis : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        //Spin around local y axis
        transform.RotateAround(transform.position, transform.up, Time.deltaTime * 90f);
    }
}
