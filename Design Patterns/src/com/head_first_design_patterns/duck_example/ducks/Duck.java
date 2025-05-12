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

    public void display() {
        System.out.println("DISPLAYING");
    }

    public void performFly() {
        flyBehaviour.fly();
    }

    public void performQuack() {
        quackBehaviour.quack();
    }
}

