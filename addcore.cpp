bool endOfJump(){
    if (onGround() != 0){
        newY = mainHero.y;
        return false;
    } else {
        if (mainHero.y - newY >= 200){
            return true;
        }
    }
    return false;
}
