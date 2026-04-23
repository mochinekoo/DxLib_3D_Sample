#define _CRT_SECURE_NO_WARNINGS
#include "BootScene.h"
#include "TestDraw.h"
#include <DxLib.h>

namespace {
	TestDraw* testDraw = new TestDraw();
	static VECTOR vector = VECTOR(640, 360, 0);
	static VECTOR target = VECTOR(20.0, 0, 0);
}

BootScene::BootScene()
  : SceneBase("BootScene") {
	count = 0;
	handle_ = -1;
	Init();
}

void BootScene::Init() {
	count = 0;
	testDraw->Init();
	handle_ = MV1LoadModel("iii.mv1");
	ChangeLightTypeDir(VGet(-1.0f, 1.0f, -1.0f));
	MV1SetPosition(handle_, VGet(20.0, 0, 0));
	SetCameraPositionAndTarget_UpVecY(vector, target);
}

void BootScene::Update() {
	static int result = 0;
	count++;
	testDraw->Update();

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		vector.y += 10;
		target.y += 10;
	}
	if (CheckHitKey(KEY_INPUT_LSHIFT)) {
		vector.y -= 10;
		target.y -= 10;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		vector.z -= 10;
		target.z -= 10;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		vector.z += 10;
		target.z += 10;
	}
	if (CheckHitKey(KEY_INPUT_W)) {
		vector.x -= 10;
		target.x -= 10;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		vector.x += 10;
		target.x += 10;
	}

	SetCameraPositionAndTarget_UpVecY(vector, target);
}

void BootScene::Draw() {
	static int result = 0;
	//testDraw->Draw();
	//auto loc = MV1GetPosition(handle_);
	auto loc = GetCameraPosition();
	char aa[256] = {};
	sprintf(aa, "%f,%f\n", loc.x, loc.y);
	OutputDebugString(aa);
	result = MV1DrawModel(handle_);
}
