using UnityEngine;
using UnityEngine.UI;

public class xCoordinate : MonoBehaviour
{
    public Transform player;
    public Text xCoordinateText;

    // Update is called once per frame
    void Update()
    {
        xCoordinateText.text = player.position.x.ToString("0");
    }
}
