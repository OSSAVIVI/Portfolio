using UnityEngine;

public class MagicLampTrigger : MonoBehaviour
{
    public GameManager gameManager;

    private void OnTriggerEnter()
    {
        gameManager.CompleteLevel();
    }
}
