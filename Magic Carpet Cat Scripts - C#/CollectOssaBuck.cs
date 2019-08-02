using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollectOssaBuck : MonoBehaviour
{
    public AudioSource collectSoundOssaBuck;

    void OnTriggerEnter(Collider other)
    {
            GetComponent<BoxCollider>().enabled = false;
            collectSoundOssaBuck.Play();
            ScoringSystemOssabuck.theScore += 1;
            Destroy(gameObject);
    }
}
