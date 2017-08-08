﻿/**
 * @file	JumpRamp.h
 * @brief	ジャンプ台クラス定義
 * @author	morimoto
 */
#ifndef JUMPRAMP_H
#define JUMPRAMP_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "..\GimmickBase\GimmickBase.h"


class JumpRamp : public GimmickBase
{
public:
	enum TYPE
	{
		JUMPRAMP_TYPE = 0,	//!< 通常のジャンプ台.
		JUMPRAMP2_TYPE = 1,	//!< ジャンプ台2.
		JUMPRAMP3_TYPE = 2	//!< ジャンプ台3.
	};

	/**
	 * コンストラクタ
	 */
	JumpRamp();

	/**
	 * デストラクタ
	 */
	virtual ~JumpRamp();

	/**
	 * 初期化処理
	 * @return 初期化に成功したらtrue 失敗したらfalse
	 */
	virtual bool Initialize();

	/**
	 * 終了処理
	 */
	virtual void Finalize();

	/**
	 * オブジェクトの更新
	 */
	virtual void Update();

	/**
	 * オブジェクトの描画
	 */
	virtual void Draw();

	/**
	 * ギミックの追加
	 * @param[in] _pos 追加するギミックの座標
	 */
	virtual void AddGimmick(D3DXVECTOR2 _pos);

	/**
	 * ギミックの追加
	 * @param[in] _pos 追加するギミックの座標
	 */
	virtual void AddGimmick(D3DXVECTOR2 _pos, int _type);

	/**
	 * ギミックの削除
	 */
	virtual void RemoveGimmick();

	/**
	 * ギミックの削除
	 * @param[in] _pos 削除するギミックの座標
	 */
	virtual void RemoveGimmick(D3DXVECTOR2 _pos);

	/**
	 * ギミックの追加
	 * @param[in] _pos 追加するギミックの座標
	 */
	virtual void RemoveGimmick(D3DXVECTOR2 _pos, int _type);

	/**
	 * 矩形との衝突判定
	 * @param[in] _pPos 矩形座標
	 * @param[in] _pSize 矩形サイズ
	 * @todo 名前が思いつかなかったのでとりあえずこのまま
	 */
	virtual GimmickManager::GIMMICK_TYPE Collision(D3DXVECTOR2* _pPos, D3DXVECTOR2* _pSize);

	/**
	 * 矩形との衝突判定
	 * @param[in] _pPos 矩形座標
	 * @param[in] _pSize 矩形サイズ
	 * @param[in] _pOutPos 衝突したギミックの座標
	 * @param[in] _pOutSize 衝突したギミックのサイズ
	 * @todo 名前が思いつかなかったのでとりあえずこのまま
	 */
	virtual GimmickManager::GIMMICK_TYPE Collision(
		D3DXVECTOR2* _pPos, D3DXVECTOR2* _pSize,
		D3DXVECTOR2* _pOutPos, D3DXVECTOR2* _pOutSize);

private:
	struct GIMMICK_DATA
	{
		D3DXVECTOR2 Pos;
		int GimmickType;

		GIMMICK_DATA(D3DXVECTOR2 _pos, int _type) :
			Pos(_pos),
			GimmickType(_type)
		{
		}

		bool operator == (GIMMICK_DATA _data)
		{
			if (_data.Pos == Pos &&
				_data.GimmickType == GimmickType)
			{
				return true;
			}

			return false;
		}
	};

	std::vector<GIMMICK_DATA> m_GimmickData;

	int m_TextureIndex2;
	int m_TextureIndex3;

};


#endif // JUMPRAMP_H
