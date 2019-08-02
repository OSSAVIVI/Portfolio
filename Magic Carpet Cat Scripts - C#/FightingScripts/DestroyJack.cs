using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyJack : MonoBehaviour
{
    public Rigidbody coin;
    public Transform coinPos;

    void OnCollisionEnter(Collision collisionInfo)
    {
        if (collisionInfo.collider.tag == "RainbowBlast" || collisionInfo.collider.tag == "RainBowBomb")
        {
            Rigidbody coinDrop = Instantiate(coin, coinPos.position, coinPos.rotation) as Rigidbody;
            Destroy(gameObject, 0f);

        }
    }
}
