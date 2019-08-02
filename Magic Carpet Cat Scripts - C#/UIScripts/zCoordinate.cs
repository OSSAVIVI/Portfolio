using UnityEngine;
using UnityEngine.UI;

public class zCoordinate : MonoBehaviour
{
    public Transform player;
    public Text zCoordinateText;

    // Update is called once per frame
    void Update()
    {
        zCoordinateText.text = player.position.z.ToString("0");
    }
}