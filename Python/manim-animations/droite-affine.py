from manim import *

class EquationScene(Scene):
    def construct(self):
        eq = Text("y= mx + b", font_size=72)
        self.play(Write(eq))
        self.wait(1)
