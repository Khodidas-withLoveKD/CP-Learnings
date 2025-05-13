package com.head_first_design_patterns.duck_example.ducks;

import com.head_first_design_patterns.duck_example.fly_behaviour.FlyBehaviour;
import com.head_first_design_patterns.duck_example.quack_behaviour.QuackBehaviour;

/*
* The duck class should be such that if I create a specific duck type,
* it should be easily be able to have its own fly and quack behaviour.
* But those should also come from common place (interface)
 */
public abstract class Duck {
    // duck can fly and quack
    // the behaviour should be able to change/add during runtime
    FlyBehaviour flyBehaviour;
    QuackBehaviour quackBehaviour;

    // constructor
    public Duck() {}

    public abstract void displayType();

    public void setFlyBehaviour(FlyBehaviour fb) {
        flyBehaviour = fb;
        // `this` was not required here
        // But it is perfectly fine if you do it
    }

    public void performFly() {
        flyBehaviour.fly();
    }

    public void setQuackBehaviour(QuackBehaviour qb) {
        quackBehaviour = qb;
    }

    public void performQuack() {
        quackBehaviour.quack();
    }
}

