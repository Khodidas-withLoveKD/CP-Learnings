package com.head_first_design_patterns.duck_example.fly_behaviour;

public class FlyWithWings implements FlyBehaviour {
    @Override
    public void fly() {
        System.out.println("I'm flying with wings");
    }
}
