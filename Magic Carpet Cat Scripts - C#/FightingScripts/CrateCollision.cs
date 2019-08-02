using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CrateCollision : MonoBehaviour
{
    void OnCollisionEnter(Collision collisionInfo)
    {
        Debug.Log(collisionInfo.collider.name);

        if (collisionInfo.collider.tag == "RainbowBlast" || collisionInfo.collider.tag == "RainBowBomb")
        {
            Destroy(gameObject, 0f);

        }
    }
}
