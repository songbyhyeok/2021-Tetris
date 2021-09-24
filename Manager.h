#pragma once

#include "SceneManager.h"
#include "InputManager.h"
#include "KeyManager.h"

class Manager
{
private:
	SceneManager* scene;
	InputManager* input;
	KeyManager* key;
	
public:
	// �׳� ������ �ϸ� ������Ʈ�� ���簡 �ȴ�.
	// ���۷��� ���·� ���縦 �Ѵ�.
	static Manager& Instance() {
		static Manager instance;
		return instance;
	}

	static SceneManager& Scene() {	
		return *(Instance().scene);
	}

	static InputManager& Input() {
		return *(Instance().input);
	}

	static KeyManager& Key() {
		return *(Instance().key);
	}

	Manager() {
		scene = new SceneManager();
		input = new InputManager();
		key = new KeyManager();

		scene->Init();
		key->Init();
	};
	// obj�� obj�� copy�� �� ��� �� ���� �ν��Ͻ��� ����� ���̱� ������ ���´�.
	// copy constructor ���� ������
	Manager(const Manager&) = delete;
	// copy assignment ���� ���� ������
	Manager& operator= (const Manager&) = delete;

	static void Update() 
	{
		Input().UseKeyAction();
	}
};


