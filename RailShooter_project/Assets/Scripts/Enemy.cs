using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour {

	[SerializeField] GameObject deathFX;
	[SerializeField] Transform parent; 
	[SerializeField] int scoreToAdd = 5;
	[SerializeField] int hits = 10;

	Score scoreBoard;

	void Start () {
		scoreBoard = FindObjectOfType<Score>();
		AddNonTriggerCollider ();
	}
	
	void AddNonTriggerCollider () {
		Collider boxColider = gameObject.AddComponent<BoxCollider>();
		boxColider.isTrigger = false;
	}


	void OnParticleCollision(GameObject other)
    {
		
		scoreBoard.ScoreHit(scoreToAdd);
		hits = hits - 1;
		if(hits <= 0){
		Death();
		}
	}

	void Death()
	{
		
		GameObject fx = Instantiate(deathFX,transform.position,Quaternion.identity);
		fx.transform.parent = parent;
		Destroy(gameObject);
	}
}
