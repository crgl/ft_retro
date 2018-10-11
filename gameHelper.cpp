#include <string>
#include "structs.hpp"
#include "macros.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

void	deleteBullet(t_bullets **tprev, t_bullets **tbull)
{
	if (tprev == nullptr || tbull == nullptr || *tbull == nullptr)
		return ;
	if (*tprev == nullptr)
	{
		*tprev = *tbull;
		*tbull = (*tbull)->next;
		delete (*tprev)->bullet;
		delete *tprev;
		*tprev = nullptr;
	}
	else
	{
		(*tprev)->next = (*tbull)->next;
		delete (*tbull)->bullet;
		delete *tbull;
		*tbull = (*tprev)->next;
	}
}

void	deleteEnemy(t_enemies **tprev, t_enemies **tene)
{
	if (tprev == nullptr || tene == nullptr || *tene == nullptr)
		return ;
	if (*tprev == nullptr)
	{
		*tprev = *tene;
		*tene = (*tene)->next;
		delete (*tprev)->enemy;
		delete *tprev;
		*tprev = nullptr;
	}
	else
	{
		(*tprev)->next = (*tene)->next;
		delete (*tene)->enemy;
		delete *tene;
		*tene = (*tprev)->next;
	}
}

void	bulletCheck(t_bullets **bullets)
{
	t_bullets	*tbull;
	t_bullets	*tprev;

	if (bullets == nullptr || *bullets == nullptr)
		return ;
	tprev = nullptr;
	while (*bullets != nullptr && !((*bullets)->bullet->onScreen())) {
		deleteBullet(&tprev, bullets);
	}
	tbull = *bullets;
	while (tbull != nullptr)
	{
		if (!tbull->bullet->onScreen())
			deleteBullet(&tprev, &tbull);
		else
		{
			tbull->bullet->display();
			tbull->bullet->move();
			tprev = tbull;
			tbull = tbull->next;
		}
	}
}

bool	overlaps(t_enemies *tene, t_bullets *tbull)
{
	if (tene == nullptr || tbull == nullptr || !tene->enemy->checkVisibility())
		return (false);
	if (abs(tbull->bullet->getX() - (tene->enemy->getX() + ENEMY_WIDTH / 2)) < ENEMY_WIDTH / 2 &&
		abs(tbull->bullet->getY() - tene->enemy->getY()) < ENEMY_HEIGHT)
		return (true);
	return (false);
}

void	enemyCheck(t_enemies **enemies, t_bullets **bullets)
{
	t_enemies	*tene;
	t_enemies	*tprev;
	t_bullets	*tbull;
	t_bullets	*tbprev;
	bool		flag;

	if (enemies == nullptr || *enemies == nullptr)
		return ;
	tprev = nullptr;
	while (*enemies != nullptr && !(*enemies)->enemy->onScreen())
		deleteEnemy(&tprev, enemies);
	tene = *enemies;
	while (tene != nullptr)
	{
		flag = false;
		if (!tene->enemy->onScreen())
			deleteEnemy(&tprev, &tene);
		else
		{
			if (bullets != nullptr) {
				tbull = *bullets;
				tbprev = nullptr;
				while (tbull != nullptr)
				{
					if (overlaps(tene, tbull))
					{
						tene->enemy->invisify();
						if (tbprev != nullptr) {
							deleteBullet(&tbprev, &tbull);
						}
						else {
							deleteBullet(&tbprev, bullets);
							tbull = *bullets;
						}
						flag = true;
						break ;
					}
					else
					{
						tbprev = tbull;
						tbull = tbull->next;
					}
				}
				if (tbull || flag)
					continue ;
			}
			tene->enemy->fire(bullets);
			tene->enemy->display();
			tene->enemy->move();
			tprev = tene;
			tene = tene->next;
		}
	}
}
