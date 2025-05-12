package com.head_first_design_patterns.duck_example.fly_behaviour;

public class NoFly implements FlyBehaviour {
    @Override
    public void fly() {
        System.out.println("I cannot fly");
    }
}
