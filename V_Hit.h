#ifndef V_HIT_H_INCLUDED
#define V_HIT_H_INCLUDED

void Hit(Player &player, Enemy &enemy, InputState &inputstate) {
    int rx = abs(player.GetPosX() - enemy.GetPosX());
    int ry = abs(player.GetPosY() - enemy.GetPosY());
    if (rx <= 8 && ry <= 3 && enemy.isAlive()) {
        if (enemy.m_TimerAttack.elapsed() >= enemy.GetAttackSpeed()) {
            player.takeDamage(enemy.GetDamage());
            enemy.m_TimerAttack.reset();
        }
        if (inputstate.IsHit.previous) {
            if (player.m_TimerAttack.elapsed() >= player.GetAttackSpeed()) {
                enemy.takeDamage(player.GetDamage());
                player.m_TimerAttack.reset();
            }
            if (!enemy.isAlive()) {
                player.AddExp(1);
                player.AddToken(5);
            }
        }
    }
}

#endif // V_HIT_H_INCLUDED
