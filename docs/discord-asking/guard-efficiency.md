I'd like to talk about "optimization" and "efficiency".
I got an actor that acts as a "guard". When he spots link *(when "yaw towards player" is less than 45deg)*, 
the main music's volume fades down, and the enemy-battle sequence plays on the player's sub bgm.

The problem in all of that is that if I put more than one (2+) of these "guard actors" 
in one room/scene, something weird will happen:
If one guard sees Link, he'll set a local boolean of his called `spottedPlayer` to `true`, 
and will proceed into playing the battle music. But the other guard will not see the player, 
so it will set its own `spottedPlayer` to `false`, and will instead proceed 
into playing back the original sequence it was playing before spotting the player.

You see the problem? If one guard see Link, he plays the battle music. 
While the other guard CAN'T see Link, so he will stop the battle music.

The solution I found is to add an `union` called `guardStuff` in the player's struct `Player`. 
To this union, I added  a boolean: `spotted`, and a u8: `spottedCount`.
Every time a guard spots Link, it increments that count by 1 once. 
So then, I check if the "global spotted boolean" *(which is in the player's struct)* is `false`, 
then we check if the spottedCount is `0`. If the condition is met, it's only THEN that 
we allow a guard to play back the previous sequence.

Here is some code:

```c
// Code to set "player spotting booleans" correctly
bool guardSeesPlayer = Actor_IsFacingPlayer(&this->actor, DEG_TO_BINANG(45)) && this->actor.xzDistToPlayer < 500.0f;

if (!this->spottedPlayer && guardSeesPlayer) {
    this->playerPtr->guardStuff.spottedCount++;
    this->spottedPlayer = true;
    if (!this->playerPtr->guardStuff.spotted) {
        this->playerPtr->guardStuff.spotted = true;
    }
}

if ((this->playerPtr->guardStuff.spotted && !this->spottedPlayer) && 
    this->playerPtr->guardStuff.spottedCount == 0) {
    this->playerPtr->guardStuff.spotted = false;
}
if (this->spottedPlayer && !guardSeesPlayer) {
    this->playerPtr->guardStuff.spottedCount--;
    this->spottedPlayer = false;
}

// ...

// Code to check music playing:
if (this->playerPtr->guardStuff.spotted && !this->bgmLowered) {
    Audio_SetMainBgmVolume(0x10, GUARD_BGM_FADE_DURATION);
    SEQCMD_PLAY_SEQUENCE(SEQ_PLAYER_BGM_SUB, GUARD_BGM_FADE_DURATION, 0, NA_BGM_ENEMY);
    this->bgmLowered = true;
} else if (!this->playerPtr->guardStuff.spotted && this->bgmLowered) {
    SEQCMD_PLAY_SEQUENCE(SEQ_PLAYER_BGM_SUB, GUARD_BGM_FADE_DURATION, 0, NA_BGM_NO_MUSIC);
    Audio_SetMainBgmVolume(0x7F, GUARD_BGM_FADE_DURATION);
    this->bgmLowered = false;
}
```