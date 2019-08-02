using UnityEngine;

public class MagicCarpetCollision : MonoBehaviour
{
    public MagicCarpetMovement movement;

    void OnCollisionEnter(Collision collisionInfo)
    {
        Debug.Log(collisionInfo.collider.name);

        if (collisionInfo.collider.tag == "Danger")
        {
            movement.enabled = false;
            FindObjectOfType<GameManager>().EndGame();

        }
    }
}
