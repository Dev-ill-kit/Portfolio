using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Rocket : MonoBehaviour {

	[SerializeField] float rotSpeed = 100f;
	[SerializeField] float flySpeed = 100f;
	[SerializeField] AudioClip flySound;
	[SerializeField] AudioClip boomSound;
	[SerializeField] AudioClip finishSound;
	[SerializeField] ParticleSystem flyPartiles;
	[SerializeField] ParticleSystem boomPartiles;
	[SerializeField] ParticleSystem finishPartiles;

	bool collisionOff = false;
	Rigidbody rigidBody;
	AudioSource audioSource;

	enum State {Playing,Dead, NextLevel};
	State state = State.Playing;

	// Use this for initialization
	void Start () {
		
		state = State.Playing;
		rigidBody = GetComponent<Rigidbody>();
		audioSource = GetComponent<AudioSource>();
	}
	
	// Update is called once per frame
	void Update () {
		if(state == State.Playing){
		Launch();
		Rotation();
		}
		if(Debug.isDebugBuild){
		DebugKeys();
		}

	}
	void DebugKeys()
	{
		if(Input.GetKeyDown(KeyCode.L))
		{
			LoadNextLevel();
		}
		else if(Input.GetKeyDown(KeyCode.C))
		{
			collisionOff = !collisionOff;
		}
	}

	void OnCollisionEnter(Collision collision)
	{
		if(state == State.Dead || state == State.NextLevel || collisionOff)
		{
			return;
		}

		switch(collision.gameObject.tag)
		{
			case "Friendly":
				print("OK");
				break;
			case "Finish":
				Finish();
				break;
			case "Battery":
				
				break;	
			default:
				Lose();
				break;

		}
	}

	

	void Lose()
	{
				state = State.Dead;
				print("RocketBoom!");
				audioSource.Stop();
				audioSource.PlayOneShot(boomSound);
				boomPartiles.Play();
				Invoke("LoadFirstLevel",2f);
	}

	void Finish()
	{
				state = State.NextLevel;
				audioSource.Stop();
				audioSource.PlayOneShot(finishSound);
				finishPartiles.Play();
				Invoke("LoadNextLevel",2f);
	}
	void LoadNextLevel() 
	{
		int currentLevelIndex = SceneManager.GetActiveScene().buildIndex;
		int nextLevelIndex = currentLevelIndex+1;  
		
		if(nextLevelIndex == SceneManager.sceneCountInBuildSettings)
		{
			nextLevelIndex = 1; 
		}

		SceneManager.LoadScene(nextLevelIndex); 

	}

	void LoadFirstLevel() 
	{
		SceneManager.LoadScene(1);
	}

	void Launch()
	{
		if(Input.GetKey(KeyCode.Space))
		{
			
			rigidBody.AddRelativeForce(Vector3.up * flySpeed * Time.deltaTime);
			if(audioSource.isPlaying == false)
			audioSource.PlayOneShot(flySound);
			flyPartiles.Play();
		}
		else
		{
			audioSource.Pause();
			flyPartiles.Stop();
		}
		
	}
	void Rotation()
	{

		float rotationSpeed = rotSpeed * Time.deltaTime;

		rigidBody.freezeRotation = true;
		if(Input.GetKey(KeyCode.A))
		{
			transform.Rotate(Vector3.forward * rotationSpeed);
		}
		else if(Input.GetKey(KeyCode.D))
		{
			transform.Rotate(-Vector3.forward * rotationSpeed);
		}
		rigidBody.freezeRotation = false;
	}
}
