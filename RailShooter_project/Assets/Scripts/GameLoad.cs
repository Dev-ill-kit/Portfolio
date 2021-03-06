using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameLoad : MonoBehaviour
{
  void Start()
    {
        
        Invoke("FirstLevelLoad", 2f);
    }

   
    void FirstLevelLoad()
    {
        SceneManager.LoadScene(1); 
         }
}
 