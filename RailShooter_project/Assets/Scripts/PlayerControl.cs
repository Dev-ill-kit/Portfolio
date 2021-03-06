using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityStandardAssets.CrossPlatformInput;

public class PlayerControl : MonoBehaviour {

	[Header("General")]
	[Tooltip("м/с")][SerializeField] float Speed = 4f;
	[SerializeField] float XClamp = 4.5f;
	[SerializeField] float YClamp = 4.5f;
	[SerializeField] GameObject[] guns;

	[Header("Rotation")]
	[SerializeField] float xRotFactor = -5f;
	[SerializeField] float yRotFactor = 5f;
	[SerializeField] float zRotFactor = 4f;

	[Header("RotationOnMove")]
	[SerializeField] float xMoveRot = -10f;
	[SerializeField] float yMoveRot = 10f;
	[SerializeField] float zMoveRot = 10f;

	bool isControlEnabled = true;
	float xMove,yMove;
	
	// Update is called once per frame
	void Update () {
		if(isControlEnabled){
		MoveShip();
		RotateShip();
		FireGuns();
		}
		
	}


	void OnPlayerDeath()
	{
		isControlEnabled = false;
	}
	void MoveShip()
	{
		xMove = CrossPlatformInputManager.GetAxis("Horizontal");
		yMove = CrossPlatformInputManager.GetAxis("Vertical");

		float xOffset = xMove * Speed * Time.deltaTime;
		float yOffset = yMove * Speed * Time.deltaTime;
		
		float newXPos = transform.localPosition.x + xOffset;
		float clampXPos = Mathf.Clamp(newXPos,-XClamp,XClamp);

		float newYPos = transform.localPosition.y + yOffset;
		float clampYPos = Mathf.Clamp(newYPos,-YClamp,YClamp);

		transform.localPosition = new Vector3(clampXPos,clampYPos,transform.localPosition.z);
	}

	void RotateShip()
	{
		float xRot = transform.localPosition.y * xRotFactor + yMove * xMoveRot;
		float yRot = transform.localPosition.x * yRotFactor + xMove * yMoveRot;
		float zRot = xMove * zMoveRot;

		transform.localRotation = Quaternion.Euler(xRot,yRot,zRot);
	}

	void FireGuns()
	{
		if(CrossPlatformInputManager.GetButton("Fire1"))
		{
			ActiveGuns();
		}
		else
		{
			DeactiveGuns();
		}
	}

	void ActiveGuns()
	{
		foreach(GameObject gun in guns)
		{
			gun.GetComponent<ParticleSystem>().enableEmission = true;
		}
	}
	void DeactiveGuns()
	{
		foreach(GameObject gun in guns)
		{
			gun.GetComponent<ParticleSystem>().enableEmission = false;
		}
	}
}
