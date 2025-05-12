package com.head_first_design_patterns.duck_example.quack_behaviour;

public class Squeak implements QuackBehaviour {
    @Override
    public void quack() {
        System.out.println("I'm squeaking");
    }
}
