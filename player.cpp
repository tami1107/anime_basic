#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "player.h"

namespace
{
	// キャラクターアニメーションのフレーム数
	constexpr int kAnimeChangeFrame = 8;
}

Player::Player()
{
	for (auto& handle : m_handle)
	{
		handle = -1;
	}
	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
	/*m_animeUp = 0;
	m_animeLeft = 24;*/
}

Player::~Player()
{
	
}

void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kPlayerGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight / 2 - kPlayerGraphicSizeY / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeUp = 0;
	m_animeLeft = 0;
}

void Player::update()
{
	
	m_animeNo = m_animeFrame / kAnimeChangeFrame;

	
	if (m_animeFrame >= kPlayerGraphicDivX * kAnimeChangeFrame)
	{
		m_animeFrame = 0;
	}

	//m_animeNo = m_animeFrame / kAnimeChangeFrame;
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;
	if (padState & PAD_INPUT_UP)
	{
		DrawString(0, 0, "UP", GetColor(255,255,255));

		m_dirNo = 3;
		isKey = true;

		m_pos.y -= kPlayerGraphicSpeed;
		if (m_pos.y < 0)
		{
			m_pos.y = 0;
		}
	}
	if (padState & PAD_INPUT_DOWN)
	{
		DrawString(0, 0, "DOWN", GetColor(255, 255, 255));

		m_dirNo = 0;
		isKey = true;

		m_pos.y += kPlayerGraphicSpeed;
		if (m_pos.y > Game::kScreenHeight-32)
		{
			m_pos.y = Game::kScreenHeight-32;
		}
	}
	if (padState & PAD_INPUT_LEFT)
	{
		DrawString(0, 0, "LEFT", GetColor(255, 255, 255));

		m_dirNo = 1;
		isKey = true;

		m_pos.x -= kPlayerGraphicSpeed;
		if (m_pos.x < 0-5)
		{
			m_pos.x = 0-5;
		}
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		DrawString(0, 0, "RIGHT", GetColor(255, 255, 255));

		m_dirNo = 2;
		isKey = true;

		m_pos.x += kPlayerGraphicSpeed;
		if (m_pos.x > Game::kScreenWidth-24)
		{
			m_pos.x = Game::kScreenWidth - 24;
		}
	}

	// キャラクターのアニメーション
	if (isKey) m_animeFrame++;

	if (m_animeFrame >= kPlayerGraphicDivX * kAnimeChangeFrame)
	{
		m_animeFrame = 0;
	}
	int tempAnimeNo = m_animeFrame / kAnimeChangeFrame;
	m_animeNo = m_dirNo * kPlayerGraphicDivX + tempAnimeNo;

}

void Player::draw()
{
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);

}