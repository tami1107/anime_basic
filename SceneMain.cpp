#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle = -1;
	}
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	LoadDivGraph("data/char.png", 12,
		3, 4,
		32, 32, m_hPlayerGraphic);

	m_player.setHandle(m_hPlayerGraphic[4]);
	m_player.init();
}

// �I������
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(m_hPlayerGraphic[4]); handle = -1;
	}
	
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
}