package com.head_first_design_patterns.duck_example.ducks;

import com.head_first_design_patterns.duck_example.fly_behaviour.FlyWithWings;
import com.head_first_design_patterns.duck_example.quack_behaviour.Quack;

public class MallardDuck extends Duck {
    public MallardDuck() {
        flyBehaviour = new FlyWithWings();
        quackBehaviour = new Quack();
        this.displayType();
    }

    public void displayType() {
        System.out.println("-----------\nI'm Mallard Duck");
    }
}
