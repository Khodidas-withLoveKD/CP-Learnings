package com.head_first_design_patterns.duck_example.quack_behaviour;

public class NoSound implements QuackBehaviour {
    @Override
    public void quack() {
        System.out.println("I cannot make sound");
    }
}
