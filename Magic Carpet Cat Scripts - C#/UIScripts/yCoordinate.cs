using UnityEngine;
using UnityEngine.UI;

public class yCoordinate : MonoBehaviour
{
    public Transform player;
    public Text yCoordinateText;

    // Update is called once per frame
    void Update()
    {
        yCoordinateText.text = player.position.y.ToString("0");
    }
}