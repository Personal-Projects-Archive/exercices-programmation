from manim import *

class EquationScene2(Scene):
    def construct(self):
        eq = Text("E = mc²")
        self.play(Write(eq))
        self.wait(1)
