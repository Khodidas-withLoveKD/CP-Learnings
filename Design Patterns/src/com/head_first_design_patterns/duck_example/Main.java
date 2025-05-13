package com.head_first_design_patterns.duck_example;

import com.head_first_design_patterns.duck_example.ducks.Duck;
import com.head_first_design_patterns.duck_example.ducks.MallardDuck;
import com.head_first_design_patterns.duck_example.ducks.ModelDuck;
import com.head_first_design_patterns.duck_example.fly_behaviour.FlyWithRocket;

public class Main {
    public static void main(String[] args) {
        Duck mallardDuck = new MallardDuck();
        mallardDuck.performFly();
        mallardDuck.performQuack();

        Duck modelDuck = new ModelDuck();
        modelDuck.performFly();
        System.out.println("Adding rockets to Model Duck");
        modelDuck.setFlyBehaviour(new FlyWithRocket());
        modelDuck.performFly();
    }
}
