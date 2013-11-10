// BulletTest2.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"

class Game;

GameEngine* GameEngineInstance = GameEngine::GetInstance();

//void renderCompoundShape(bulletObject* _compoundShape)
//{
//	btRigidBody* shape = _compoundShape->body;
//	if(shape->getCollisionShape()->getShapeType() != COMPOUND_SHAPE_PROXYTYPE)
//		return;
//
//	btTransform childTrans;
//	btTransform worldTrans;
//
//	btCollisionShape* childShape;
//
//	int numChildShapes = ((btCompoundShape*)shape->getCollisionShape())->getNumChildShapes();
//
//	for (int i = numChildShapes; i > 0; --i)
//	{
//		childShape = ((btCompoundShape*)shape->getCollisionShape())->getChildShape(i-1);
//
//		childTrans.setIdentity();
//		worldTrans.setIdentity();
//		shape->getMotionState()->getWorldTransform(worldTrans);
//		childTrans = ((btCompoundShape*)shape->getCollisionShape())->getChildTransform(i-1);
//		
//		if(childShape->getShapeType() == BOX_SHAPE_PROXYTYPE)
//		{
//			renderBox(childShape, &worldTrans,  &childTrans);
//		}
//		else if(childShape->getShapeType() == SPHERE_SHAPE_PROXYTYPE)
//		{
//			renderSphere(childShape, &worldTrans,  &childTrans);
//		}
//		else if(childShape->getShapeType() == CAPSULE_SHAPE_PROXYTYPE)
//		{
//			renderCapsule(childShape, &worldTrans,  &childTrans);
//		}
//		else if(childShape->getShapeType() == CYLINDER_SHAPE_PROXYTYPE)
//		{
//			renderCylinder(childShape, &worldTrans,  &childTrans);
//		}
//		else if(childShape->getShapeType() == CONE_SHAPE_PROXYTYPE)
//		{
//			renderCone(childShape, &worldTrans,  &childTrans);
//		}
//	}
//}

//void initPhysics()
//{
//	gameObjects.clear();
//	// init bullet handler and create world
//	bulletWorld = new BulletWorld();
//
//	Dimensions d;
//
//	d.upAxis = btVector3(0,1,0);
//	BulletCollisionShape* floor = new BulletCollisionShape(STATIC_PLANE_PROXYTYPE, d);
//	BulletRigidBody* newBody = new BulletRigidBody(bulletWorld, floor, btVector3(0,0,0),0);
//
//	d.halfExtents = btVector3(0.25, 0.5, 1.5);
//	BulletCollisionShape* box1 = new BulletCollisionShape(BOX_SHAPE_PROXYTYPE, d);
//
//	d.halfExtents = btVector3(1.5, 0.25, 0.5);
//	BulletCollisionShape* box2 = new BulletCollisionShape(BOX_SHAPE_PROXYTYPE, d);
//
//	for (int y = 0; y < 3; y++)
//	{
//		for (int x = 0; x < 5; x++)
//		{
//			BulletRigidBody* newBody = new BulletRigidBody(bulletWorld, box1, btVector3((x * 3)-8.5, (y * 1.5)+0.5, 0), 1);
//			gameObjects.push_back(newBody);
//		}
//		for (int x = 0; x < 4; x++)
//		{
//			BulletRigidBody* newBody = new BulletRigidBody(bulletWorld, box2, btVector3((x * 3) - 7, (y*1.5)+1.25, 1), 1);
//			gameObjects.push_back(newBody);
//		}
//		for (int x = 0; x < 4; x++)
//		{
//			BulletRigidBody* newBody = new BulletRigidBody(bulletWorld, box2, btVector3((x * 3) - 7, (y*1.5)+1.25, -1), 1);
//			gameObjects.push_back(newBody);
//		}
//	}
//	bulletWorld->startPhysics();
//}




//void keyboardRead(unsigned char key, int x, int y)
//{
//	if (key == 'b')
//	{
//		Dimensions d;
//		d.halfExtents = btVector3(1, 1, 1);
//		BulletRigidBody* newBody = new BulletRigidBody(bulletWorld,
//													new BulletCollisionShape(BOX_SHAPE_PROXYTYPE, d),
//													btVector3(0, 10, 0),
//													10);
//		gameObjects.push_back(newBody);
//	}
//	else if(key == 'n')
//	{
//		Dimensions d;
//		d.radius = 1;
//		BulletRigidBody* newBody = new BulletRigidBody(bulletWorld,
//													new BulletCollisionShape(SPHERE_SHAPE_PROXYTYPE, d),
//													btVector3(0, 10, 0),
//													10);
//		gameObjects.push_back(newBody);
//	}
//	else if(key == 'm')
//	{
//		Dimensions d;
//		d.halfExtents = btVector3(1, 1, 1);
//		BulletRigidBody* newBody = new BulletRigidBody(bulletWorld,
//													new BulletCollisionShape(CYLINDER_SHAPE_PROXYTYPE, d),
//													btVector3(0, 10, 0),
//													10);
//		gameObjects.push_back(newBody);
//	}
//	else if(key == 'j')
//	{
//		Dimensions d;
//		d.radius = 1;
//		d.height = 3;
//		BulletRigidBody* newBody = new BulletRigidBody(bulletWorld,
//													new BulletCollisionShape(CAPSULE_SHAPE_PROXYTYPE, d),
//													btVector3(0, 10, 0),
//													10);
//		gameObjects.push_back(newBody);
//	}
//	else if(key == 'k')
//	{
//		Dimensions d;
//		d.radius = 1;
//		d.height = 3;
//		BulletRigidBody* newBody = new BulletRigidBody(bulletWorld,
//													new BulletCollisionShape(CONE_SHAPE_PROXYTYPE, d),
//													btVector3(0, 10, 0),
//													10);
//		gameObjects.push_back(newBody);
//	}
//	else if(key == 'r')
//		initPhysics();
//	else if(key == 32)
//	{
//		float mass = 50;
//		Dimensions d;
//		d.radius = 0.5;
//		BulletRigidBody* newBody = new BulletRigidBody(bulletWorld,
//													new BulletCollisionShape(SPHERE_SHAPE_PROXYTYPE, d),
//													btVector3(13, 5, 20),
//													50);
//		gameObjects.push_back(newBody);
//		newBody->applyForce(btVector3(-500*mass, 0*mass, -750*mass));
//	}
//	else if(key == 'z')
//		--cam->zoom;
//	else if(key == 'x')
//		++cam->zoom;
//	else if(key == 'w');
//		//myBody1->setLinearVelocity(btVector3(0, 0, 10));
//	else if(key == 's');
//		//myBody1->setLinearVelocity(btVector3(0, 0, -10));
//	else if(key == 'a');
//		//myBody1->setLinearVelocity(btVector3(-10, 0, 0));
//	else if(key == 'd');
//		//myBody1->setLinearVelocity(btVector3(10, 0, 0));
//}
//
//void mouseRead(int button, int state, int x, int y)
//{
//	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//    {
//		cam->mouseRot = true;
//		cam->mouseX = x;
//		cam->mouseY = y;
//	}
//	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//    {
//		cam->mouseRot = false;
//    }
//	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//	{
//		cam->mouseMove = true;
//		cam->mouseX = x;
//		cam->mouseY = y;
//	}
//	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
//	{
//		cam->mouseMove = false;
//	}
//}
//
//void mouseTrack(int x, int y)
//{
//	if (cam->mouseRot)
//	{
//		cam->rotateY(((float)x - cam->mouseX)/4);
//		cam->rotateX(((float)y - cam->mouseY)/4);
//		cam->mouseX = x;
//		cam->mouseY = y;
//	}
//	else if (cam->mouseMove)
//	{
//		cam->updatePos(((float)x - cam->mouseX)/4,((float)y - cam->mouseY)/4);
//		cam->mouseX = x;
//		cam->mouseY = y;
//	}
//}


int main(int argc, char **argv)
{
	openDebugOutputFile();

	GameEngineInstance->Init(argc, argv);

	Game* game = new Game("game");
	game->Init();
	GameEngineInstance->AddScreen(game);
	GameEngineInstance->SwitchTo("game");

	disableDebugOutput();

	GameEngineInstance->MainLoop();

	closeDebugOutputFile();
}