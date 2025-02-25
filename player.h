#pragma once

#include "Vec2.h"

class Player
{
public:
	// 定数定義

	// プレイヤーグラフィック分割数
	static constexpr int kPlayerGraphicDivX = 3;
	static constexpr int kPlayerGraphicDivY = 4;
	static constexpr int kPlayerGraphicDivNum = kPlayerGraphicDivX * kPlayerGraphicDivY;

	// プレイヤーグラフィックサイズ
	static constexpr int kPlayerGraphicSizeX = 32;
	static constexpr int kPlayerGraphicSizeY = 32;

	// プレイヤーの歩行速度
	static constexpr  float kPlayerGraphicSpeed = 5.0f;

public:
	Player();
	virtual ~Player();

	// グラフィックデータ設定
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	// プレイヤーの初期化
	void init();

	// 処理
	void update();
	// 描画
	void draw();

private:
	int m_handle[kPlayerGraphicDivNum];

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	// キャラクターのアニメーション
	int m_animeNo; // 表示する番号
	int m_animeFrame;
	int m_dirNo;   // 進行方向
	int m_animeUp; // 上に歩く
	int m_animeLeft;
};