#define _CRT_SECURE_NO_WARNINGS
#include "BootScene.h"
#include "TestDraw.h"
#include <DxLib.h>

namespace {
	TestDraw* testDraw = new TestDraw();
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
	ChangeLightTypeDir(VGet(0.0f, 1.0f, 0.0f));
	MV1SetPosition(handle_, VGet(20.0, 0, 0));
}

void BootScene::Update() {
	static int result = 0;
	count++;
	testDraw->Update();

}

void BootScene::Draw() {
	static int result = 0;
	//testDraw->Draw();
	auto loc = MV1GetPosition(handle_);
	char aa[256] = {};
	sprintf(aa, "%f,%f\n", loc.x, loc.y);
	OutputDebugString(aa);
	result = MV1DrawModel(handle_);
}
