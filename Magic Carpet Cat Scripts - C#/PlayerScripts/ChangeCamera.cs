using UnityEngine;

public class ChangeCamera : MonoBehaviour
{
    public Camera mainCam;
    public Camera frontCam;

    public bool frontCamMode;

      // Start is called before the first frame update
    void Start()
    {
        mainCam.enabled = true;
        frontCam.enabled = false;

        frontCamMode = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyUp(KeyCode.P) && frontCamMode == false)
        {
            mainCam.enabled = !mainCam.enabled;
            frontCam.enabled = !frontCam.enabled;

            frontCamMode = true;
        }
       
        else if (Input.GetKeyUp(KeyCode.P) && frontCamMode == true)
        {
            mainCam.enabled = !mainCam.enabled;
            frontCam.enabled = !frontCam.enabled;

            frontCamMode = false;
        }
    }
}
