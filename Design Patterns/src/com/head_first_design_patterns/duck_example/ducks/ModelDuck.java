package com.head_first_design_patterns.duck_example.ducks;

import com.head_first_design_patterns.duck_example.fly_behaviour.NoFly;
import com.head_first_design_patterns.duck_example.quack_behaviour.Quack;

// duck whose behaviour can be changed at runtime
public class ModelDuck extends Duck{
    public ModelDuck() {
        flyBehaviour = new NoFly();
        quackBehaviour = new Quack();
        this.displayType();
    }

    public void displayType() {
        System.out.println("---------\nI'm a model duck");
    }
}
