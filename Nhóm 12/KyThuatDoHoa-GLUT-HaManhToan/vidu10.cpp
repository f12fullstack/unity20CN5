//
// Ky thuat do hoa
// Ha Manh Toan hmtoan@ioit.ac.vn
//
//#include <stdlib.h>
#include <iostream>
#include <glut.h>
#include "imageloader.h"
#include "texturemodel.h"
#include "model.h"
#include <math.h>
using namespace std;

namespace vd10 {
	
	
	GLuint _textureBrick, _textureDoor, _textureGrass, _textureRoof, _textureWindow, _textureSky, _textureSkyTop;
	
	TextureModel sky, skyTop, grass, wall_1,wall_2 ,wall_21,wall_22,wall_23,wall_3, wall_4, wall_5,wall_6, wall_7, wall_8,wallt,walltr,cay,cayt1,cayt,cua,topcua,
		col_g, col_m, top, top1, topc, top2, top3, top4, top5,top7, thang_1, thang_12, thangb_2, thangb_3, thangb_4, thangben, thangt, thangmid, bonhoa, de, cot, co, door, ngang, doc,cheot, cheop,daunga,dausac;
	
	Vector3 sky_t, skyTop_t, top_1, topc_t, top_2, top_3, top_4, top_5, top_6,top_7, cay_t, cay_t1,cayt1_t1,cayt1_t2,cayt1_t3,cayt1_t4, cua_t1, cua_t2, cua_t3, cua_t4, topcua_t, grass_t, wall1_t1, wall2_t2, wallt_t1, wallt_t2,walltr_t, wall2_t21, wall2_t22, thangmid_t1,
		thangmid_t2, thangmid_t3, bonhoa_t1, bonhoa_t2, wall2_t23, wall3_t3, wall4_t4, wall5_t5, wall6_t6, wall7_t7, wall8_t8, thang1_t1, thang1_t2, thangb2_t1, thangb2_t2, thangb3_t1, thangb3_t2, thangb4_t1, thangb4_t2, thangben_t1, thangben_t2, thangt_t1,
		thangt_t2, de_t, cot_t, co_t,thang12_t1, thang12_t2, colg_t1, colg_t2, colg_t3, colg_t4, colm_t1, colm_t2, colm_t3, colm_t4, colm_t5, colm_t6, colm_t7, colm_t8, colm_t9, colm_t10, colm_t11, colm_t12, colm_t13, colm_t14, colm_t15, colm_t16,door_t
		,cot_t1,cot_t2,ngang_t1,ngang_t2,ngang_t3,ngang_t4,ngang_t5,ngang_t6,ngang_t7,ngang_t8,ngang_t9,ngang_t10,doc_t1,doc_t2,doc_t3,doc_t4,doc_t5,doc_t6,cheot_t1, cheot_t2,cheop_t1,cheop_t2,cheop_t3,daunga_t1,daunga_t2,daunga_t3,daunga_t4,dausac_t;
	
	float lx = 0.0f, lz = 0.0f;
	float x = 0.0f, z = 80.0f;
	float angle = -1.5f;
	float speed = 0.1f;
	float heightAngle = 0;
	float height_view = 30;
	
	void draw(TextureModel* m, Vector3 t) {
		glPushMatrix();
		glTranslatef(t.x, t.y, t.z);
		m->draw();
		glPopMatrix();
	}
	void makeSky() {
		sky.clear();
		sky.setTextureFromBMP("data/sky.bmp");
		sky.addVertex(point3(-200, -200, -200));//0
		sky.addVertex(point3(200, -200, -200));//1
		sky.addVertex(point3(-200, 200, -200));//2
		sky.addVertex(point3(200, 200, -200));//3

		sky.addVertex(point3(-200, -200, 200));//4
		sky.addVertex(point3(200, -200, 200));//5
		sky.addVertex(point3(-200, 200, 200));//6
		sky.addVertex(point3(200, 200, 200));//7
		sky.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		sky_t = point3(0, 0, 0);
	}
	void makeSkyTop() {
		skyTop.clear();
		skyTop.setTextureFromBMP("data/skytop.bmp");
		skyTop.addVertex(point3(-200, 200, -200));
		skyTop.addVertex(point3(200, 200, -200));
		skyTop.addVertex(point3(200, 200, 200));
		skyTop.addVertex(point3(-200, 200, 200));
		skyTop.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		skyTop_t = point3(0, 0, 0);
	}
	void makeGrass() {
		grass.clear();
		grass.setTextureFromBMP("data/grass.bmp");
		grass.addVertex(point3(-50, -1.5, 50));
		grass.addVertex(point3(-50, -1.5, -50));
		grass.addVertex(point3(50, -1.5, -50));
		grass.addVertex(point3(50, -1.5, 50));
		grass.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 50), texCoord2(50, 50), texCoord2(50, 0), texCoord2(0, 0)));
		
		grass_t = point3(0, 0, 0);
	}

	/// ///////////////////

	void makeNgang() {
		ngang.clear();
		ngang.setTextureFromBMP("data/hcm.bmp");
		ngang.addVertex(point3(-1, -0.6, -0.8));//0
		ngang.addVertex(point3(1, -0.6, -0.8));//0.8
		ngang.addVertex(point3(-1, 0.6, -0.8));//5
		ngang.addVertex(point3(1, 0.6, -0.8));//3

		ngang.addVertex(point3(-1, -0.6, 0.8));//5
		ngang.addVertex(point3(1, -0.6, 0.8));//5
		ngang.addVertex(point3(-1, 0.6, 0.8));//5
		ngang.addVertex(point3(1, 0.6, 0.8));//6

		ngang.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		ngang.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		ngang.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		ngang.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		ngang.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		ngang_t1 = point3(21.8, 0.8, 50);
		ngang_t2 = point3(26, 1.3, 50);
		ngang_t3 = point3(36.8, 0.8, 50);
		ngang_t4 = point3(36.8, 3.6, 50);
		ngang_t5 = point3(37.6, 1.5, 50);
		ngang_t6 = point3(42.5, 2, 50);
		ngang_t7 = point3(42.5, 0.8, 50);
		ngang_t8 = point3(52.8, 0.8, 50);
		ngang_t9 = point3(52.8, 3.6, 50);
		ngang_t10 = point3(47, 1.3, 50);
	}
	void makeDoc() {
		doc.clear();
		doc.setTextureFromBMP("data/hcm.bmp");
		doc.addVertex(point3(-0.8, -2, -0.8));//0
		doc.addVertex(point3(0.8, -2, -0.8));//0.8
		doc.addVertex(point3(-0.8, 2, -0.8));//5
		doc.addVertex(point3(0.8, 2, -0.8));//3

		doc.addVertex(point3(-0.8, -2, 0.8));//5
		doc.addVertex(point3(0.8, -2, 0.8));//5
		doc.addVertex(point3(-0.8, 2, 0.8));//5
		doc.addVertex(point3(0.8, 2, 0.8));//6

		doc.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		doc.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		doc.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		doc.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		doc.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		doc_t1 = point3(20, 2.2, 50);
		doc_t2 = point3(30, 2.2, 50);
		doc_t3 = point3(33, 2.2, 50);
		doc_t4 = point3(35, 2.2, 50);
		doc_t5 = point3(40.2, 2.2, 50);
		
		doc_t6 = point3(51, 2.2, 50);
	}
	void makeCheot() {
		cheot.clear();
		cheot.setTextureFromBMP("data/hcm.bmp");
		cheot.addVertex(point3(-0.8, -2, -0.8));//0
		cheot.addVertex(point3(0.8, -2, -0.8));//0.8
		cheot.addVertex(point3(1.2, 2, -0.8));//5
		cheot.addVertex(point3(2.8, 2, -0.8));//3

		cheot.addVertex(point3(-0.8, -2, 0.8));//5
		cheot.addVertex(point3(0.8, -2, 0.8));//5
		cheot.addVertex(point3(1.2, 2, 0.8));//5
		cheot.addVertex(point3(2.8, 2, 0.8));//6

		cheot.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheot.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheot.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheot.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheot.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheot_t1 = point3(24, 2.2, 50);
		cheot_t2 = point3(45, 2.2, 50);
	}
	void makeCheop() {
		cheop.clear();
		cheop.setTextureFromBMP("data/hcm.bmp");
		cheop.addVertex(point3(-0.8, -2, -0.8));//0
		cheop.addVertex(point3(0.8, -2, -0.8));//0.8
		cheop.addVertex(point3(-2.8, 2, -0.8));//5
		cheop.addVertex(point3(-1.2, 2, -0.8));//3

		cheop.addVertex(point3(-0.8, -2, 0.8));//5
		cheop.addVertex(point3(0.8, -2, 0.8));//5
		cheop.addVertex(point3(-2.8, 2, 0.8));//5
		cheop.addVertex(point3(-1.2, 2, 0.8));//6

		cheop.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheop.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheop.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheop.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheop.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cheop_t1 = point3(28, 2.2, 50);
		cheop_t2 = point3(32.5, 2.2, 50);
		cheop_t3 = point3(49, 2.2, 50);
	}
	void makeNga() {
		daunga.clear();
		daunga.setTextureFromBMP("data/hcm.bmp");
		daunga.addVertex(point3(-1, -0.4, -0.8));//0
		daunga.addVertex(point3(1, -0.4, -0.8));//0.8
		daunga.addVertex(point3(-1.5, 0.4, -0.8));//5
		daunga.addVertex(point3(1.5, 0.4, -0.8));//3

		daunga.addVertex(point3(-1, -0.4, 0.8));//5
		daunga.addVertex(point3(1, -0.4, 0.8));//5
		daunga.addVertex(point3(-1.5, 0.4, 0.8));//5
		daunga.addVertex(point3(1.5, 0.4, 0.8));//6

		daunga.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		daunga.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		daunga.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		daunga.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		daunga.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		daunga_t1 = point3(26, 5, 50);
		daunga_t2 = point3(42, 2.2, 50);
		daunga_t3 = point3(42, 0.6, 50);
		//daunga_t4 = point3(42, 3.6, 50);
	}
	void makeSac() {
		dausac.clear();
		dausac.setTextureFromBMP("data/hcm.bmp");
		dausac.addVertex(point3(-0.8, -0.4, -0.8));//0
		dausac.addVertex(point3(0.8, -0.4, -0.8));//0.8
		dausac.addVertex(point3(0.2, 0.4, -0.8));//5
		dausac.addVertex(point3(1.8, 0.4, -0.8));//3

		dausac.addVertex(point3(-0.8, -0.4, 0.8));//5
		dausac.addVertex(point3(0.8, -0.4, 0.8));//5
		dausac.addVertex(point3(0.2, 0.4, 0.8));//5
		dausac.addVertex(point3(1.8, 0.4, 0.8));//6

		dausac.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		dausac.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		dausac.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		dausac.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		dausac.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		dausac_t = point3(47, 5, 50);
		
	}
	//////////////////////////////////////

	void makeWall_1(){
		
		wall_1.clear();
		wall_1.setTextureFromBMP("data/mauxam.bmp");

		wall_1.addVertex(point3(-46, -0.7, -46));//0
		wall_1.addVertex(point3(46, -0.7, -46));//1
		wall_1.addVertex(point3(-46, 0.7, -46));//7
		wall_1.addVertex(point3(46, 0.7, -46));//3
		
		wall_1.addVertex(point3(-46, -0.7, 46));//7
		wall_1.addVertex(point3(46, -0.7, 46));//7
		wall_1.addVertex(point3(-46, 0.7, 46));//7
		wall_1.addVertex(point3(46, 0.7, 46));//7
		
		wall_1.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_1.addQuad(quadIndex(6,7,5,4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_1.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_1.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall1_t1 = point3(0, -0.8, 0);
		
	}	
	void makeWall_2() {

		wall_2.clear();
		wall_2.setTextureFromBMP("data/mauxam.bmp");

		wall_2.addVertex(point3(-26, -8, -26));//0
		wall_2.addVertex(point3(26, -8, -26));//1
		wall_2.addVertex(point3(-26, 8, -26));//2
		wall_2.addVertex(point3(26, 8, -26));//3

		wall_2.addVertex(point3(-26, -8, 16));//4
		wall_2.addVertex(point3(26, -8, 16));//5
		wall_2.addVertex(point3(-26, 8, 16));//6
		wall_2.addVertex(point3(26, 8, 16));//7

		wall_2.addVertex(point3(-21.5, 8, -26));//8
		wall_2.addVertex(point3(-21.5, 8, 16));//9

		wall_2.addVertex(point3(21.5, 8, -26));//10
		wall_2.addVertex(point3(21.5, 8, 16));//11

		wall_2.addVertex(point3(-21.5, 8, -21.5));//10
		wall_2.addVertex(point3(21.5, 8, -21.5));//11



		wall_2.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_2.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_2.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall_2.addQuad(quadIndex(2, 8, 9, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_2.addQuad(quadIndex(10, 3, 7, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_2.addQuad(quadIndex(8, 10, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall2_t2 = point3(0,7.9, 0);

	}
	void makeWall_21() {

		wall_21.clear();
		wall_21.setTextureFromBMP("data/mauxam.bmp");

		wall_21.addVertex(point3(-21.5, -8, -21.5));//0
		wall_21.addVertex(point3(21.5, -8, -21.5));//1
		wall_21.addVertex(point3(-21.5, 8, -21.5));//2
		wall_21.addVertex(point3(21.5, 8, -21.5));//3

		wall_21.addVertex(point3(-21.5, -8, 16));//4
		wall_21.addVertex(point3(21.5, -8, 16));//5
		wall_21.addVertex(point3(-21.5, 8, 16));//6
		wall_21.addVertex(point3(21.5, 8, 16));//7

		wall_21.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		//wall_21.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_21.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_21.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall2_t21 = point3(0, 7.9, 0);

	}
	void makeWall_22() {

		wall_22.clear();
		wall_22.setTextureFromBMP("data/mauxam.bmp");

		wall_22.addVertex(point3(-26, -8, 19));//0
		wall_22.addVertex(point3(26, -8, 19));//1
		wall_22.addVertex(point3(-26, 8, 19));//2
		wall_22.addVertex(point3(26, 8, 19));//3

		wall_22.addVertex(point3(-26, -8, 26));//4
		wall_22.addVertex(point3(26, -8, 26));//5
		wall_22.addVertex(point3(-26, 8, 26));//6
		wall_22.addVertex(point3(26, 8, 26));//7

		wall_22.addVertex(point3(-21.5, 8, 19));//8
		wall_22.addVertex(point3(-21.5, 8, 26));//9

		wall_22.addVertex(point3(21.5, 8, 19));//10
		wall_22.addVertex(point3(21.5, 8, 26));//11

		wall_22.addVertex(point3(-21.5, 8, 21.5));//12
		wall_22.addVertex(point3(21.5, 8, 21.5));//13
		//wall_22.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		
		//wall_22.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_22.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_22.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_22.addQuad(quadIndex(2, 8, 9, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_22.addQuad(quadIndex(10, 3, 7, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_22.addQuad(quadIndex(13, 12, 9, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall2_t22 = point3(0, 7.9, 0);

	}
	void makeWalltrc() {
		wallt.clear();
		wallt.setTextureFromBMP("data/mauxamtrc.bmp");
		//mat tren
		wallt.addVertex(point3(-8.5, 6, -8.5));//0
		wallt.addVertex(point3(8.5, 6, -8.5));//1


		//mat duoi
		wallt.addVertex(point3(-8.5, -6, -8.5));//0
		wallt.addVertex(point3(8.5, -6, -8.5));//1
		//mat tren
		

		//mat sau
		wallt.addQuad(quadIndex(0, 1, 3, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wallt_t1 = point3(17.5, 5.5, 34.5);
		wallt_t2 = point3(-17.5, 5.5, 34.5);

	}
	void makeWallttren() {
		walltr.clear();
		walltr.setTextureFromBMP("data/mauxamtren.bmp");
		//mat tren
		walltr.addVertex(point3(-26, 2.3, -26));//0
		walltr.addVertex(point3(26, 2.3, -26));//1


		//mat duoi
		walltr.addVertex(point3(-26, -2.3, -26));//0
		walltr.addVertex(point3(26, -2.3, -26));//1
		//mat tren


		//mat sau
		walltr.addQuad(quadIndex(0, 1, 3, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		walltr_t = point3(0, 13.6, 52);
		

	}
	void makeWall_23() {

		wall_23.clear();
		wall_23.setTextureFromBMP("data/mauxam.bmp");

		wall_23.addVertex(point3(-21.5, -8, 19));//0
		wall_23.addVertex(point3(21.5, -8, 19));//2
		wall_23.addVertex(point3(-21.5, 8, 19));//21.5
		wall_23.addVertex(point3(21.5, 8, 19));//3

		wall_23.addVertex(point3(-21.5, -8, 21.5));//21.5
		wall_23.addVertex(point3(21.5, -8, 21.5));//21.5
		wall_23.addVertex(point3(-21.5, 8, 21.5));//21.5
		wall_23.addVertex(point3(21.5, 8, 21.5));//6

		//wall_23.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_23.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_23.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_23.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall2_t23 = point3(0, 7.9, 0);

	}
	void makeWall_3() {

		wall_3.clear();
		wall_3.setTextureFromBMP("data/mauxam.bmp");

		wall_3.addVertex(point3(-16, -2.1, -16));//0
		wall_3.addVertex(point3(16, -2.1, -16));//2.1
		wall_3.addVertex(point3(-16, 2.1, -16));//2.1
		wall_3.addVertex(point3(16, 2.1, -16));//3

		wall_3.addVertex(point3(-16, -2.1, 16));//2.1
		wall_3.addVertex(point3(16, -2.1, 16));//2.1
		wall_3.addVertex(point3(-16, 2.1, 16));//2.1
		wall_3.addVertex(point3(16, 2.1, 16));//6

		wall_3.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_3.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_3.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_3.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall3_t3 = point3(0, 16.5, -0);

	}
	void makeWall_4() {

		wall_4.clear();
		wall_4.setTextureFromBMP("data/mauxam.bmp");

		wall_4.addVertex(point3(-13, -1, -13));//0
		wall_4.addVertex(point3(13, -1, -13));//1
		wall_4.addVertex(point3(-13, 1, -13));//5
		wall_4.addVertex(point3(13, 1, -13));//3

		wall_4.addVertex(point3(-13, -1, 13));//5
		wall_4.addVertex(point3(13, -1, 13));//5
		wall_4.addVertex(point3(-13, 1, 13));//5
		wall_4.addVertex(point3(13, 1, 13));//6

		wall_4.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_4.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_4.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_4.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall4_t4 = point3(0, 19.5, -0);

	}
	void makeWall_5() {

		wall_5.clear();
		wall_5.setTextureFromBMP("data/maudo.bmp");

		wall_5.addVertex(point3(-8.5, -8, -8.5));//0
		wall_5.addVertex(point3(8.5, -8, -8.5));//8
		wall_5.addVertex(point3(-8.5, 8, -8.5));//5
		wall_5.addVertex(point3(8.5, 8, -8.5));//3

		wall_5.addVertex(point3(-8.5, -8, 8.5));//5
		wall_5.addVertex(point3(8.5, -8, 8.5));//5
		wall_5.addVertex(point3(-8.5, 8, 8.5));//5
		wall_5.addVertex(point3(8.5, 8, 8.5));//6

		wall_5.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_5.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_5.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_5.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall5_t5 = point3(0, 28.5, -0);

	}
	void makeWall_6() {
		wall_6.clear();
		wall_6.setTextureFromBMP("data/mauxam.bmp");
		wall_6.addVertex(point3(-12, -1.5, -12));//0
		wall_6.addVertex(point3(12, -1.5, -12));//1
		wall_6.addVertex(point3(-13, 1.5, -13));//2
		wall_6.addVertex(point3(13, 1.5, -13));//3
		wall_6.addVertex(point3(-12, -1.5, 12));//4
		wall_6.addVertex(point3(12, -1.5, 12));//5
		wall_6.addVertex(point3(-13, 1.5, 13));//6
		wall_6.addVertex(point3(13, 1.5, 13));//7

		wall_6.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_6.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_6.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_6.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall_6.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall6_t6 = point3(0, 38, -0);
	}
	void makeWall_7() {

		wall_7.clear();
		wall_7.setTextureFromBMP("data/mauxam.bmp");

		wall_7.addVertex(point3(-9.5, -0.8, -9.5));//0
		wall_7.addVertex(point3(9.5, -0.8, -9.5));//0.8
		wall_7.addVertex(point3(-9.5, 0.8, -9.5));//5
		wall_7.addVertex(point3(9.5, 0.8, -9.5));//3

		wall_7.addVertex(point3(-9.5, -0.8, 9.5));//5
		wall_7.addVertex(point3(9.5, -0.8, 9.5));//5
		wall_7.addVertex(point3(-9.5, 0.8, 9.5));//5
		wall_7.addVertex(point3(9.5, 0.8, 9.5));//6
		//

		wall_7.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_7.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_7.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_7.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_7.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall7_t7 = point3(0, 40.6, -0);

	}
	void makeWall_8() {

		wall_8.clear();
		wall_8.setTextureFromBMP("data/mauxam.bmp");

		wall_8.addVertex(point3(-7, -1, -7));//0
		wall_8.addVertex(point3(7, -1, -7));//1
		wall_8.addVertex(point3(-7, 1, -7));//5
		wall_8.addVertex(point3(7, 1, -7));//3

		wall_8.addVertex(point3(-7, -1, 7));//5
		wall_8.addVertex(point3(7, -1, 7));//5
		wall_8.addVertex(point3(-7, 1, 7));//5
		wall_8.addVertex(point3(7, 1, 7));//6
		//

		wall_8.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_8.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_8.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_8.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		wall_8.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		wall8_t8 = point3(0, 42.4, -0);

	}
	
	void makeThang_1 () {
		thang_1.clear();
		thang_1.setTextureFromBMP("data/mauxam.bmp");
		thang_1.addVertex(point3(-7.5, -8, -7.5));//0
		thang_1.addVertex(point3(7.5, -8, -7.5));//2
		thang_1.addVertex(point3(-7.5, 8, -7.5));//3
		thang_1.addVertex(point3(7.5, 8, -7.5));//3

		thang_1.addVertex(point3(-7.5, -8, -6));//3
		thang_1.addVertex(point3(7.5, -8, -6));//3
		thang_1.addVertex(point3(-7.5, 8, -6));//3
		thang_1.addVertex(point3(7.5, 8, -6));//6

		thang_1.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang_1.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang_1.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang_1.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang_1.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang1_t1 = point3(29, 8, 22);

		thang1_t2 = point3(-29, 8, 22);
	}
	void makeThang_12() {
		thang_12.clear();
		thang_12.setTextureFromBMP("data/maudot.bmp");
		thang_12.addVertex(point3(-6.5, -6.6,-7));//0
		thang_12.addVertex(point3(7, -6.6,-7));//2
		thang_12.addVertex(point3(-6.5,6.6, -7));//3
		thang_12.addVertex(point3(7, 6.6, -7));//3

		thang_12.addVertex(point3(-6.5, -6.6, -4));//3
		thang_12.addVertex(point3(7, -6.6, -4));//3
		thang_12.addVertex(point3(-6.5, 6.6, -4));//3
		thang_12.addVertex(point3(7, 6.6, -4));//6

		thang_12.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang_12.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang_12.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thang_12.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		thang_12.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		thang12_t1 = point3(28, 6.6, 23);
		thang12_t2 = point3(-28, 6.6, 23);
	}
	void makeThangB_2() {
		thangb_2.clear();
		thangb_2.setTextureFromBMP("data/maudot.bmp");
		thangb_2.addVertex(point3(-2.95, -5, -7.5));//0
		thangb_2.addVertex(point3(6.2, -5, -7.5));//2
		thangb_2.addVertex(point3(-2.95, 5, -7.5));//3
		thangb_2.addVertex(point3(6.2, 5, -7.5));//3

		thangb_2.addVertex(point3(-2.95, -5, -4));//3
		thangb_2.addVertex(point3(6.2, -5, -4));//3
		thangb_2.addVertex(point3(-2.95, 5, -4));//3
		thangb_2.addVertex(point3(6.2, 5, -4));//6

		thangb_2.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_2.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_2.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_2.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_2.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb2_t1 = point3(29, 5, 26.5);
		thangb2_t2 = point3(-32, 5, 26.5);
	}
	void makeThangB_3() {
		thangb_3.clear();
		thangb_3.setTextureFromBMP("data/maudot.bmp");
		thangb_3.addVertex(point3(-2.95, -3.5, -7.5));//0
		thangb_3.addVertex(point3(6.2, -3.5, -7.5));//2
		thangb_3.addVertex(point3(-2.95, 3.5, -7.5));//3
		thangb_3.addVertex(point3(6.2, 3.5, -7.5));//3

		thangb_3.addVertex(point3(-2.95, -3.5, -4));//3
		thangb_3.addVertex(point3(6.2, -3.5, -4));//3
		thangb_3.addVertex(point3(-2.95, 3.5, -4));//3
		thangb_3.addVertex(point3(6.2, 3.5, -4));//6

		thangb_3.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_3.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_3.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_3.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_3.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb3_t1 = point3(29, 3.5, 29.5);
		thangb3_t2 = point3(-32, 3.5, 29.5);

	}
	void makeThangB_4() {
		thangb_4.clear();
		thangb_4.setTextureFromBMP("data/maudot.bmp");
		thangb_4.addVertex(point3(-10, -2, -10));//0
		thangb_4.addVertex(point3(10, -2, -10));//2
		thangb_4.addVertex(point3(-10, 2, -10));//3
		thangb_4.addVertex(point3(10, 2, -10));//3

		thangb_4.addVertex(point3(-10, -2, -6.5));//3
		thangb_4.addVertex(point3(10, -2, -6.5));//3
		thangb_4.addVertex(point3(-10, 2, -6.5));//3
		thangb_4.addVertex(point3(10, 2, -6.5));//6

		thangb_4.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_4.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_4.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_4.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb_4.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangb4_t1 = point3(26.4, 1.5, 35.5);
		thangb4_t2 = point3(-26.4, 1.5, 35.5);

	}
	void makeThangBen() {
		thangben.clear();
		thangben.setTextureFromBMP("data/mauxam.bmp");
		thangben.addVertex(point3(-0.75, -8, -2));//0
		thangben.addVertex(point3(0.75, -8, -2));//8
		thangben.addVertex(point3(-0.75, 8, -2));//3
		thangben.addVertex(point3(0.75, 8, -2));//3

		thangben.addVertex(point3(-0.75, -8, 13.5));//3
		thangben.addVertex(point3(0.75, -8, 13.5));//3
		thangben.addVertex(point3(-0.75, 8, 13.5));//3
		thangben.addVertex(point3(0.75, 8, 13.5));//6

		thangben.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangben.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangben.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangben.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		thangben.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		//thangben.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangben_t1 = point3(36, 8, 17.2);
		thangben_t2 = point3(-36, 8, 17.2);

	}
	void makeThangT() {
		thangt.clear();
		thangt.setTextureFromBMP("data/mauxam.bmp");
		thangt.addVertex(point3(-9.5, -3.5, -10));//0
		thangt.addVertex(point3(9.5, -3.5, -10));//2
		thangt.addVertex(point3(-9.5, 3.5, -10));//3
		thangt.addVertex(point3(9.5, 3.5, -10));//3

		thangt.addVertex(point3(-9.5, -3.5, -8.5));//3
		thangt.addVertex(point3(9.5, -3.5, -8.5));//3
		thangt.addVertex(point3(-9.5, 3.5, -8.5));//3
		thangt.addVertex(point3(9.5, 3.5, -8.5));//6

		thangt.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangt.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangt.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangt.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangt.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		thangt_t1 = point3(25.85, 3.5, 39.2);
		thangt_t2 = point3(-25.85, 3.5, 39.2);

	}
	void makeThangmid() {
		thangmid.clear();
		thangmid.setTextureFromBMP("data/maudot.bmp");
		thangmid.addVertex(point3(-16.5, -0.6, -7.5));//0
		thangmid.addVertex(point3(16.5, -0.6, -7.5));//2
		thangmid.addVertex(point3(-16.5, 0.6, -7.5));//3
		thangmid.addVertex(point3(16.5, 0.6, -7.5));//3

		thangmid.addVertex(point3(-16.5, -0.6, -4));//3
		thangmid.addVertex(point3(16.5, -0.6, -4));//3
		thangmid.addVertex(point3(-16.5, 0.6, -4));//3
		thangmid.addVertex(point3(16.5, 0.6, -4));//6

		thangmid.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangmid.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangmid.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangmid.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangmid.addQuad(quadIndex(2, 3, 7, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		thangmid_t1 = point3(0, 2.9, 33);

		thangmid_t2 = point3(0, 1.7, 36.5);
		thangmid_t3 = point3(0, 0.5	, 40);
	}

	void makeBonhoa() {

		bonhoa.clear();
		bonhoa.setTextureFromBMP("data/mauxam.bmp");

		bonhoa.addVertex(point3(-10, -0.7, -8));//0
		bonhoa.addVertex(point3(10, -0.7, -8));//1
		bonhoa.addVertex(point3(-10, 0.7, -8));//7
		bonhoa.addVertex(point3(10, 0.7, -8));//3

		bonhoa.addVertex(point3(-10, -0.7, -3));//7
		bonhoa.addVertex(point3(10, -0.7, -3));//7
		bonhoa.addVertex(point3(-10, 0.7, -3));//7
		bonhoa.addVertex(point3(10, 0.7, -3));//7

		bonhoa.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bonhoa.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bonhoa.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bonhoa.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		bonhoa_t1 = point3(27, 0.7, 43);
		bonhoa_t2 = point3(-27, 0.7, 43);

	}
	void makeDe() {

		de.clear();
		de.setTextureFromBMP("data/mauxam.bmp");

		de.addVertex(point3(-3, -0.7, -3));//0
		de.addVertex(point3(3, -0.7, -3));//1
		de.addVertex(point3(-3, 0.7, -3));//7
		de.addVertex(point3(3, 0.7, -3));//3

		de.addVertex(point3(-3, -0.7, 3));//7
		de.addVertex(point3(3, -0.7, 3));//7
		de.addVertex(point3(-3, 0.7, 3));//7
		de.addVertex(point3(3, 0.7, 3));//7
		
		de.addVertex(point3(-3, 0.7, -3));
		de.addVertex(point3(3, 0.7, -3));
		de.addVertex(point3(3, 0.7, 3));
		de.addVertex(point3(-3, 0.7, 3));

		de.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		de.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		de.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		de.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		de.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		de_t = point3(0, -0.8, 53);

	}
	void makeCot() {

		cot.clear();
		cot.setTextureFromBMP("data/maudo.bmp");

		cot.addVertex(point3(-0.3, -12, -0.3));//0
		cot.addVertex(point3(0.3, -12, -0.3));//2
		cot.addVertex(point3(-0.3, 12, -0.3));//0.3
		cot.addVertex(point3(0.3, 12, -0.3));//3

		cot.addVertex(point3(-0.3, -12, 0.3));//0.3
		cot.addVertex(point3(0.3, -12, 0.3));//0.3
		cot.addVertex(point3(-0.3, 12, 0.3));//0.3
		cot.addVertex(point3(0.3, 12, 0.3));//6

		cot.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cot.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cot.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cot.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cot_t = point3(0, 12, 53);
	
	}
	void makeCua() {

		cua.clear();
		cua.setTextureFromBMP("data/mauxam.bmp");

		cua.addVertex(point3(-1, -4, -1));//0
		cua.addVertex(point3(1, -4, -1));//1
		cua.addVertex(point3(-1, 4, -1));//5
		cua.addVertex(point3(1, 4, -1));//3

		cua.addVertex(point3(-1, -4, 1));//5
		cua.addVertex(point3(1, -4, 1));//5
		cua.addVertex(point3(-1, 4, 1));//5
		cua.addVertex(point3(1, 4, 1));//6

		cua.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cua.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cua.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cua.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cua_t1 = point3(6, 7.5, 23);
		cua_t2 = point3(-6, 7.5, 23);
		cua_t3 = point3(8, 7.5, 25);
		cua_t4 = point3(-8, 7.5, 25);

	}
	void makeTopcua() {
		topcua.clear();
		topcua.setTextureFromBMP("data/mauxam.bmp");
		//mat tren
		topcua.addVertex(point3(-6, 4, -2));//0
		topcua.addVertex(point3(6, 4, -2));//1
		topcua.addVertex(point3(6, 4, 0));//2
		topcua.addVertex(point3(8, 4, 0));//3

		topcua.addVertex(point3(8, 4, 2));//0
		topcua.addVertex(point3(-8, 4, 2));//1
		topcua.addVertex(point3(-8, 4, 0));//2
		topcua.addVertex(point3(-6, 4, 0));//3

		//mat duoi
		topcua.addVertex(point3(-6, -4, -2));//0
		topcua.addVertex(point3(6, -4, -2));//1
		topcua.addVertex(point3(6, -4, 0));//2
		topcua.addVertex(point3(8, -4, 0));//3

		topcua.addVertex(point3(8, -4, 2));//0
		topcua.addVertex(point3(-8, -4, 2));//1
		topcua.addVertex(point3(-8, -4, 0));//2
		topcua.addVertex(point3(-6, -4, 0));//3

		topcua.addQuad(quadIndex(0, 1, 2, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		topcua.addQuad(quadIndex(3, 4, 5, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		topcua.addQuad(quadIndex(8, 9, 10, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		topcua.addQuad(quadIndex(11, 12, 13, 14, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		//mat sau
		//topcua.addQuad(quadIndex(0, 1, 9, 8, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		topcua_t = point3(0, 7.5, 24);
	}
	void makeDoor() {
		door.clear();
		door.setTextureFromBMP("data/door1.bmp");
		//mat tren
		door.addVertex(point3(-6, 4, -2));//0
		door.addVertex(point3(6, 4, -2));//1


		//mat duoi
		door.addVertex(point3(-6, -4, -2));//0
		door.addVertex(point3(6, -4, -2));//1


		//mat sau
		door.addQuad(quadIndex(0, 1, 3, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		door_t = point3(0, 7.5, 24);
	}


	void makeCo() {
		co.clear();
		co.setTextureFromBMP("data/quockys.bmp");
		co.addVertex(point3(-10, -3.5, -3.5));//0
		co.addVertex(point3(3.5, -3.5, -3.5));//1
		co.addVertex(point3(-10, 3.5, -3.5));//2
		co.addVertex(point3(3.5, 3.5, -3.5));//3
		

		//co.addQuad(quadIndex(2,3,1,0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		co.addQuad(quadIndex(0, 1, 3, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		co_t = point3(-3.4, 20, 56.5);
		

	}
	void makeColg() {

		col_g.clear();
		col_g.setTextureFromBMP("data/colmauxam.bmp");

		col_g.addVertex(point3(-1.2, -8, -1.2));//0
		col_g.addVertex(point3(1.2, -8, -1.2));//1.2
		col_g.addVertex(point3(-1.2, 8, -1.2));//5
		col_g.addVertex(point3(1.2, 8, -1.2));//3

		col_g.addVertex(point3(-1.2, -8, 1.2));//5
		col_g.addVertex(point3(1.2, -8, 1.2));//5
		col_g.addVertex(point3(-1.2, 8, 1.2));//5
		col_g.addVertex(point3(1.2, 8, 1.2));//6

		col_g.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		col_g.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		col_g.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		col_g.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		colg_t1 = point3(10, 28.5, 10);
		colg_t2 = point3(-10, 28.5, 10);
		colg_t3 = point3(10, 28.5, -10);
		colg_t4 = point3(-10, 28.5, -10);

	}
	void makeColm() {

		col_m.clear();
		col_m.setTextureFromBMP("data/colmauxam.bmp");

		col_m.addVertex(point3(-0.8, -8, -0.8));//0
		col_m.addVertex(point3(0.8, -8, -0.8));//0.8
		col_m.addVertex(point3(-0.8, 8, -0.8));//5
		col_m.addVertex(point3(0.8, 8, -0.8));//3

		col_m.addVertex(point3(-0.8, -8, 0.8));//5
		col_m.addVertex(point3(0.8, -8, 0.8));//5
		col_m.addVertex(point3(-0.8, 8, 0.8));//5
		col_m.addVertex(point3(0.8, 8, 0.8));//6

		col_m.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		col_m.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		col_m.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		col_m.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		colm_t1 = point3(10, 28.5,6);
		colm_t2 = point3(10, 28.5, 2);
		colm_t3 = point3(10, 28.5, -2);
		colm_t4 = point3(10, 28.5, -6);
		colm_t5 = point3(-10, 28.5, 6);
		colm_t6 = point3(-10, 28.5, 2);
		colm_t7 = point3(-10, 28.5, -2);
		colm_t8 = point3(-10, 28.5, -6);

		colm_t9 = point3(-6, 28.5, -10);
		colm_t10 = point3(-2, 28.5, -10);
		colm_t11 = point3(2, 28.5, -10);
		colm_t12 = point3(6, 28.5, -10);

		colm_t13 = point3(-6, 28.5, 10);
		colm_t14 = point3(-2, 28.5, 10);
		colm_t15 = point3(2, 28.5, 10);
		colm_t16 = point3(6, 28.5, 10);
	}
	void makeTop() {
		
		top.clear();
		top.setTextureFromBMP("data/mauxam.bmp");
		top.addVertex(point3(-46, 0.7, -46));
		top.addVertex(point3(46, 0.7, -46));
		top.addVertex(point3(46, 0.7, 46));
		top.addVertex(point3(-46, 0.7, 46));
		top.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		top_1 = point3(0, -0.8, 0);
	}
	void makeTopc() {

		topc.clear();
		topc.setTextureFromBMP("data/mauxam.bmp");
		topc.addVertex(point3(-3, 0.7, -3));
		topc.addVertex(point3(3, 0.7, -3));
		topc.addVertex(point3(3, 0.7, 3));
		topc.addVertex(point3(-3, 0.7, 3));
		topc.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//topc_t = point3(0, -0.8, 53);
	}
	void makeTop1() {

		top1.clear();
		top1.setTextureFromBMP("data/maudo.bmp");
		top1.addVertex(point3(-21.5, 16.7, -21.5));
		top1.addVertex(point3(21.5, 16.7, -21.5));
		top1.addVertex(point3(21.5, 16.7, 21.5));
		top1.addVertex(point3(-21.5, 16.7, 21.5));
		top1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		top_2 = point3(0, -3.5, 0);
	}
	void makeTop2() {

		top2.clear();
		top2.setTextureFromBMP("data/mauxam.bmp");
		top2.addVertex(point3(-16, 18.8, -16));
		top2.addVertex(point3(16, 18.8, -16));
		top2.addVertex(point3(16, 18.8, 16));
		top2.addVertex(point3(-16, 18.8, 16));
		top2.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		top_3 = point3(0, -0.2, 0);
	}
	void makeTop3() {

		top3.clear();
		top3.setTextureFromBMP("data/mauxam.bmp");
		top3.addVertex(point3(-13, 19.5, -13));
		top3.addVertex(point3(13, 19.5, -13));
		top3.addVertex(point3(13, 19.5, 13));
		top3.addVertex(point3(-13, 19.5, 13));
		top3.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		top_4 = point3(0, 1, 0);
	}
	void makeTop4() {

		top4.clear();
		top4.setTextureFromBMP("data/mauxam.bmp");
		top4.addVertex(point3(-12, 35.5, -12));
		top4.addVertex(point3(12, 35.5, -12));
		top4.addVertex(point3(12, 35.5, 12));
		top4.addVertex(point3(-12, 35.5, 12));
		top4.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		top_5 = point3(0, 1, 0);
	}
	/*void makeTop5() {

		top5.clear();
		top5.setTextureFromBMP("data/mauxam.bmp");
		top5.addVertex(point3(-8.5, 38.6, -8.5));
		top5.addVertex(point3(8.5, 38.6, -8.5));
		top5.addVertex(point3(8.5, 38.6, 8.5));
		top5.addVertex(point3(-8.5, 38.6, 8.5));
		top5.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		top_6 = point3(0, 1.7, 0);
	}*/
	void makeTop7() {
		top7.clear();
		top7.setTextureFromBMP("data/grass.bmp");
		
		top7.addVertex(point3(-10, 0, -9));
		top7.addVertex(point3(10, 0, -9));
		top7.addVertex(point3(10, 0, -4));
		top7.addVertex(point3(-10, 0, -4));

		

		top7.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		top_6 = point3(-27, 1, 44);
		top_7 = point3(27, 1, 44);
	}
	//ve cay 
	void makeTree() {

		cay.clear();
		cay.setTextureFromBMP("data/lacay.bmp");

		//cay.addVertex(point3(-3, 2.5, -3));//0a
		//cay.addVertex(point3(0, 2.5, -4.5));//2.5b
		//cay.addVertex(point3(3, 2.5, -3));//2c
		//cay.addVertex(point3(4.5, 2.5, 0));//3d

		//cay.addVertex(point3(3, 2.5, 3));//4e
		//cay.addVertex(point3(0, 2.5, 4.5));//5f
		//cay.addVertex(point3(-2, 2.5, 3));//6g
		//cay.addVertex(point3(-4.5, 2.5, 0));//2.5h

		cay.addVertex(point3(-0.5, 2.5, -0.5));//0a
		cay.addVertex(point3(0, 2.5, -2));//2.5b
		cay.addVertex(point3(0.5, 2.5, -0.5));//2c
		cay.addVertex(point3(2, 2.5, 0));//3d

		cay.addVertex(point3(0.5, 2.5, 0.5));//4e
		cay.addVertex(point3(0, 2.5, 2));//5f
		cay.addVertex(point3(-0.5, 2.5, 0.5));//6g
		cay.addVertex(point3(-2, 2.5, 0));//2.5h

		cay.addVertex(point3(-4, -2.5, -4));//8a
		cay.addVertex(point3(0, -2.5, -5.5));//9b
		cay.addVertex(point3(4, -2.5, -4));//2.50c
		cay.addVertex(point3(5.5, -2.5, 0));//2.52.5d

		cay.addVertex(point3(4, -2.5, 4));//2.52e
		cay.addVertex(point3(0, -2.5, 5.5));//2.53f
		cay.addVertex(point3(-4, -2.5, 4));//2.54g
		cay.addVertex(point3(-5.5, -2.5, 0));//15h

		cay.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(0, 3, 4, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(7, 4, 5, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cay.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(8, 11, 12, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(15, 12, 13, 14, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cay.addQuad(quadIndex(0, 1, 9, 8, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(1, 2, 10, 9, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(2, 3, 11, 10, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		
		cay.addQuad(quadIndex(3, 4, 12, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(4, 5, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(5, 6, 14, 13, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		
		cay.addQuad(quadIndex(6, 7, 15, 14, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cay.addQuad(quadIndex(7, 0, 8, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		
		cay_t = point3(20, 17, 38);
		cay_t1 = point3(-20, 17, 38);

	}
	void makeTree1() {

		cayt1.clear();
		cayt1.setTextureFromBMP("data/lacay.bmp");

		cayt1.addVertex(point3(-0.5, 4, -0.5));//0a
		cayt1.addVertex(point3(0, 4, -2));//4b
		cayt1.addVertex(point3(0.5, 4, -0.5));//2c
		cayt1.addVertex(point3(2, 4, 0));//3d

		cayt1.addVertex(point3(0.5, 4, 0.5));//4e
		cayt1.addVertex(point3(0, 4, 2));//5f
		cayt1.addVertex(point3(-0.5, 4, 0.5));//6g
		cayt1.addVertex(point3(-2, 4, 0));//4h



		cayt1.addVertex(point3(-8, -4, -8));//8a
		cayt1.addVertex(point3(0, -4, -8.5));//9b
		cayt1.addVertex(point3(7, -4, -7));//70c
		cayt1.addVertex(point3(8.5, -4, 0));//77d

		cayt1.addVertex(point3(7, -4, 7));//72e
		cayt1.addVertex(point3(0, -4, 8.5));//73f
		cayt1.addVertex(point3(-7, -4, 7));//74g
		cayt1.addVertex(point3(-8.5, -4, 0));//15h

		cayt1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(0, 3, 4, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(7, 4, 5, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt1.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(8, 11, 12, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(15, 12, 13, 14, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt1.addQuad(quadIndex(0, 1, 9, 8, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(1, 2, 10, 9, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(2, 3, 11, 10, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt1.addQuad(quadIndex(3, 4, 12, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(4, 5, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(5, 6, 14, 13, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt1.addQuad(quadIndex(6, 7, 15, 14, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt1.addQuad(quadIndex(7, 0, 8, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt1_t1 = point3(20, 12, 38);
		cayt1_t2 = point3(-20, 12, 38);
		cayt1_t3 = point3(20, 7, 38);
		cayt1_t4 = point3(-20, 7, 38);
	}
	void makeTreet() {

		cayt.clear();
		cayt.setTextureFromBMP("data/mauthanc.bmp");

		cayt.addVertex(point3(-0.5, -2, -0.5));//8a
		cayt.addVertex(point3(0, -2, -1));//9b
		cayt.addVertex(point3(-0.5, -2, 0.5));//20c
		cayt.addVertex(point3(1, -2, 0));//22d

		cayt.addVertex(point3(-0.5, -2, -0.5));//22e
		cayt.addVertex(point3(0, -2, 1));//23f
		cayt.addVertex(point3(0.5, -2, -0.5));//24g
		cayt.addVertex(point3(-1, -2, 0));//15h
		cayt.addVertex(point3(-0.3, 2, -0.3));//0a
		cayt.addVertex(point3(0, 2, -1.8));//2b
		cayt.addVertex(point3(0.3, 2, -0.3 )) ;//2c
		cayt.addVertex(point3(1.8, 2, 0));//3d

		cayt.addVertex(point3(0.3, 2, 0.3));//4e
		cayt.addVertex(point3(0, 2, 1.8));//5f
		cayt.addVertex(point3(-0.3, 2, 0.3));//6g
		cayt.addVertex(point3(-1.8, 2, 0));//2h



		

		cayt.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(0, 3, 4, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(7, 4, 5, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(8, 11, 12, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(15, 12, 13, 14, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt.addQuad(quadIndex(0, 1, 9, 8, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(1, 2, 10, 9, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(2, 3, 11, 10, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt.addQuad(quadIndex(3, 4, 12, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(4, 5, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(5, 6, 14, 13, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cayt.addQuad(quadIndex(6, 7, 15, 14, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		cayt.addQuad(quadIndex(7, 0, 8, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		cot_t1 = point3(20, 3, 38);
		cot_t2 = point3(-20, 3, 38);

	}
	void resize(int width, int height) {
		if (height== 0) height = 1;
		const float ar = (float)width / (float)height;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
		gluPerspective(45.0f, ar, 0.1f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void renderScene(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		
		gluLookAt(x,30.0f, z,
			x + lx, height_view , z + lz,
			0.0f,1.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);

		draw(&sky, sky_t);
		draw(&skyTop, skyTop_t);
		for (int x1=-10; x1<10; x1++) {
			for (int z1=-10; z1<10; z1++) {
				Vector3 grass_t1;
				grass_t1.x = x1;
				grass_t1.z = z1;
				grass_t1.y = 0;

				draw(&grass, grass_t1);
			}
		}
		draw(&wall_1, wall1_t1);
		draw(&wall_2, wall2_t2);
		draw(&wall_21, wall2_t21);
		draw(&wall_22, wall2_t22);
		draw(&wall_23, wall2_t23);
		draw(&wall_3, wall3_t3);
		draw(&wall_4, wall4_t4);
		draw(&wall_5, wall5_t5);
		draw(&wall_6, wall6_t6);
		draw(&wall_7, wall7_t7);
		draw(&wall_8, wall8_t8);
		draw(&col_g, colg_t1);
		draw(&col_g, colg_t2);
		draw(&col_g, colg_t3);
		draw(&col_g, colg_t4);
		draw(&col_m, colm_t1);
		draw(&col_m, colm_t2);
		draw(&col_m, colm_t3);
		draw(&col_m, colm_t4);
		draw(&col_m, colm_t5);
		draw(&col_m, colm_t6);
		draw(&col_m, colm_t7);
		draw(&col_m, colm_t8);
		draw(&col_m, colm_t9);
		draw(&col_m, colm_t10);
		draw(&col_m, colm_t11);
		draw(&col_m, colm_t12);
		draw(&col_m, colm_t13);
		draw(&col_m, colm_t14);
		draw(&col_m, colm_t15);
		draw(&col_m, colm_t16);
		draw(&top, top_1);
		draw(&top1, top_2);
		draw(&top2, top_3);
		draw(&top3, top_4);
		draw(&top4, top_5);
		draw(&top7, top_6);
		draw(&top7, top_7);
		draw(&thang_1, thang1_t1);
		draw(&thang_1, thang1_t2);
		draw(&thang_12, thang12_t1);
		draw(&thang_12, thang12_t2);
		draw(&thangb_2, thangb2_t1);
		draw(&thangb_2, thangb2_t2);
		draw(&thangb_3, thangb3_t1);
		draw(&thangb_3, thangb3_t2);
		draw(&thangb_4, thangb4_t1);
		draw(&thangb_4, thangb4_t2);
		draw(&thangben, thangben_t1);
		draw(&thangben, thangben_t2);
		draw(&thangt, thangt_t1);
		draw(&thangt, thangt_t2);
		draw(&thangmid, thangmid_t1);
		draw(&thangmid, thangmid_t2);
		draw(&thangmid, thangmid_t3);
		draw(&cua, cua_t1);
		draw(&cua, cua_t2);
		draw(&cua, cua_t3);
		draw(&cua, cua_t4);
		draw(&door, door_t);
		draw(&wallt, wallt_t1);
		draw(&wallt, wallt_t2);
		draw(&walltr, walltr_t);
		draw(&topcua, topcua_t);
		draw(&bonhoa,bonhoa_t1);
		draw(&bonhoa, bonhoa_t2);
		draw(&cay, cay_t);
		draw(&cay, cay_t1);
		draw(&cayt1, cayt1_t1);
		draw(&cayt1, cayt1_t2);
		draw(&cayt1, cayt1_t3);
		draw(&cayt1, cayt1_t4);
		draw(&cayt, cot_t1);
		draw(&cayt, cot_t2);
		draw(&de, de_t);
		draw(&topc, topc_t);
		draw(&cot, cot_t);
		draw(&co, co_t);
		draw(&ngang , ngang_t1);
		draw(&ngang, ngang_t2);
		draw(&ngang, ngang_t3);
		draw(&ngang, ngang_t4);
		draw(&ngang, ngang_t5);
		draw(&ngang, ngang_t6);
		draw(&ngang, ngang_t7);
		draw(&ngang, ngang_t8);
		draw(&ngang, ngang_t9);
		draw(&ngang, ngang_t10);
		draw(&daunga, daunga_t1);
		draw(&daunga, daunga_t2);
		draw(&daunga, daunga_t3);
		draw(&doc, doc_t1);
		draw(&doc, doc_t2);
		draw(&doc, doc_t3);
		draw(&doc, doc_t4);
		draw(&doc, doc_t5);
		draw(&doc, doc_t6);
		draw(&dausac, dausac_t);
		draw(&cheot, cheot_t1);
		draw(&cheot, cheot_t2);
		draw(&cheop, cheop_t1);
		draw(&cheop, cheop_t2);
		draw(&cheop, cheop_t3);
		glutSwapBuffers();
		glFlush();
	}
	
	
	void processKeys(unsigned char key, int xx, int yy) {
		switch (key) {
		case '>':
			speed += 0.1;
			break;
		case '<':
			speed -= 0.1;
			break;
		case 'w':
			if (heightAngle < PI / 2) {
				heightAngle += 0.1;
				height_view = sin(heightAngle)/10 - 1;
			}
			break;
		case 's':
			if (heightAngle > (-PI / 2)) {
				heightAngle -= 0.1;
				height_view = sin(heightAngle) - 1;
			}
			break;
		case 'a':
			angle -= 0.02f;
			lx = cos(angle)*10;
			lz = sin(angle)*10;
			break;
		case 'd':
			angle += 0.02f;
			lx = cos(angle)*10;
			lz = sin(angle)*10;
			break;
		default:
			break;
		}
		glutPostRedisplay();
	}
	void processSpecialKeys(int key, int xx, int yy) {

		float fraction = speed;

		switch (key) {
		case GLUT_KEY_LEFT:
			x += lz * fraction;
			z -= lx * fraction;
			break;
		case GLUT_KEY_RIGHT:
			x -= lz * fraction;
			z += lx * fraction;
			break;
		case GLUT_KEY_UP:
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			x -= lx * fraction;
			z -= lz * fraction;
			break;
		}glutPostRedisplay();
	}

	void init() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		lx = cos(angle);
		lz = sin(angle);
		makeSky();
		makeSkyTop();
		makeGrass();
		makeNgang();
		makeDoc();
		makeCheot();
		makeCheop();
		makeNga();
		makeSac();
		makeWall_1();
		makeWall_2();
		makeWall_21();
		makeWall_22();
		makeWall_23();
		makeWall_3();
		makeWall_4();
		makeWall_5();
		makeWall_6();
		makeWall_7();
		makeWall_8();
		makeColg();
		makeColm();
		makeTop();
		makeTop1();
		makeTop2();
		makeTop3();
		makeTop4();
		//makeTop5();
		makeTop7();
		makeThang_1();
		makeThang_12();
		makeThangB_2();
		makeThangB_3();
		makeThangB_4();
		makeThangBen();
		makeThangT();
		makeThangmid();
		makeCua();
		makeTopcua();
		makeDoor();
		makeWalltrc();
		makeWallttren();
		makeTree();
		makeTree1();
		makeTreet();
		makeBonhoa();
		makeDe();
		makeTopc();
		makeCot();
		makeCo();
		
	}
}
int vidu10(int argc, char **argv) {
	//glutInit(&argc, argv);
	glutInitDisplayMode(/*GLUT_DOUBLE | GLUT_RGBA | */GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(600,600);
	glutCreateWindow("opengl");
	glEnable(GL_DEPTH_TEST);

	glutReshapeFunc(vd10::resize);
	glutKeyboardFunc(vd10::processKeys);
	glutSpecialFunc(vd10::processSpecialKeys);
	glutDisplayFunc(vd10::renderScene);
	vd10::init();
	
	glutMainLoop();
	return 0;
}
