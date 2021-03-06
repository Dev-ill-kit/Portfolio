using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Music : MonoBehaviour {

	// Use this for initialization
	void Awake()
	{
		
		int numMusic = FindObjectsOfType<Music>().Length;
		if (numMusic > 1)
		{
			Destroy(gameObject);
		}
		else{
		DontDestroyOnLoad(gameObject);
		}
	}
}
