//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneNameInput.h"
#include "GameHead.h"


//�Q�[�����C���̏��������\�b�h
void CSceneNameInput::InitScene()
{
	//�l�[�����̓I�u�W�F�N�g�̍쐬
	CObjNameInput* p = new CObjNameInput();
	Objs::InsertObj(p, OBJ_NAME_INPUT, 5);
}

//�Q�[�����C���̎��s�����\�b�h
void CSceneNameInput::Scene()
{

}


