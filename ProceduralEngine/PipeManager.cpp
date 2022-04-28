#include "PipeManager.h"

PipeManager::PipeManager(Scene* scene)
{
	this->scene = scene;
}

void PipeManager::start()
{
	buildPipe(9.5f);
	buildPipe(15.5f);
	buildPipe(21.5f);
	buildPipe(26.5f);
	buildPipe(32.5f);
	buildPipe(38.5f);
}

void PipeManager::update()
{
	//Yeah this field is ugly but oh whale
	bool spawnedPipeThisFrame = false;
	for (int i = pipes.size() -1; i >= 0; i--)
	{
		if (pipes[i][0]->getTransform()->getPosition().x < -17.0f)
		{
			for (int j = 0; j < pipes[i].size(); j++)
			{
				scene->destroyGameObject(pipes[i][j]);
			}
			pipes.erase(pipes.begin() + i);
			buildPipe(17.5f);
		}
	}


}

void PipeManager::buildPipe(float x)
{
	int gapSize = Random::generateRandomInt(3, 6);
	int gapStart = Random::generateRandomInt(6, 10);
	std::vector<GameObject*> p;
	for (int i = 0; i < 19; i++)
	{
		if (i < gapStart || i > gapStart + gapSize)
		{
			GameObject* pipeBody = scene->addGameObject(new GameObject());
			pipeBody->setTransform(x, -9 + i, 0, 1, 1);
			pipeBody->addComponent(scene->drawManager.createSpriteRenderer("PipeBody"));
			pipeBody->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(1, 1)));
			pipeBody->addComponent(new MoveLeft());
			p.push_back(pipeBody);
		}
	}
	pipes.push_back(p);
}
