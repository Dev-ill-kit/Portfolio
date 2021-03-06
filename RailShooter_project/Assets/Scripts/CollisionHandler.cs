using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour {
	[Tooltip("В секундах")][SerializeField] float LoadLevelDelay;
	[Tooltip("Префаб эффекта взрыва")][SerializeField] GameObject explosionFX;
	void OnTriggerEnter(Collider collision)
	{   
		if (collision.gameObject.tag == "Finish"){
		SceneManager.LoadScene(2);
		}
		else{
			StartDeath();
		explosionFX.SetActive(true);
		Invoke("RestartLevel",LoadLevelDelay);
		
		}

	}

	void StartDeath()
	{ 
		SendMessage("OnPlayerDeath");
	}

	void RestartLevel()
	{
		SceneManager.LoadScene(1);
	}

}
