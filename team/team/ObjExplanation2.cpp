//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjExplanation2.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjExplanation2::Init()
{
	m_key_flag=false;
}

//�A�N�V����
void CObjExplanation2::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if(Input ::GetVKey(VK_RETURN)==true)
	{
		if(m_key_flag==true)
		{
			//�����I�u�W�F�N�g1�쐬
			CObjExplanation* obj=new CObjExplanation();//�����I�u�W�F�N�g2�쐬
			Objs::InsertObj(obj,OBJ_EXPLANATION,10);

			this->SetStatus(false);//�����I�u�W�F�N�g2�j��
			
		}
	}
	else
	{
		m_key_flag=true;
	}

}

//�h���[
void CObjExplanation2::Draw()
{
	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	
	//�؂���ʒu
	RectSet(0.0f,0.0f,1024.0f,1024.0f,src);

	//�\���ʒu
	RectSet(0.0f,0.0f,1024.0f,768.0f,dst);
	
	Draw::Draw(22,&src,&dst,c,0.0f);//�`��


	Font::StrDraw(L"1/3",950,10,30,c);

	Font::StrDraw(L"Next Page : PushEnterKey",300,540,32,c);
}