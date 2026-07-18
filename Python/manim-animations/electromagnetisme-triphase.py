from manim import *
import numpy as np

# 1. Bobine simple
class Bobine(Scene):
    def construct(self):
        arcs = VGroup()
        for i in range(6):
            arc = Arc(radius=0.5, angle=PI, start_angle=0, arc_center=[i*0.3, 0, 0])
            arcs.add(arc)
        
        bobine = VGroup(*arcs).shift(LEFT*0.7)
        fleche = Arrow(start=LEFT*2, end=RIGHT*2, buff=0.1, color=RED)

        self.play(Create(bobine))
        self.play(GrowArrow(fleche))
        self.wait(2)

# 2. Sinusoïdes triphasées
class Triphase(Scene):
    def construct(self):
        axes = Axes(
            x_range=[0, 10, 1],
            y_range=[-2, 2, 1],
            axis_config={"color": GREY},
        ).scale(0.7)

        def sin_phase(phase, color):
            return axes.plot(lambda x: np.sin(x + phase), color=color)

        sin_A = sin_phase(0, RED)
        sin_B = sin_phase(2*PI/3, GREEN)
        sin_C = sin_phase(4*PI/3, BLUE)

        self.play(Create(axes))
        self.play(Create(sin_A), Create(sin_B), Create(sin_C))
        self.wait(3)

# 3. Champ tournant (vecteurs triphasés en rotation)
class ChampTournant(Scene):
    def construct(self):
        cercle = Circle(radius=2, color=GREY)
        self.play(Create(cercle))

        vecteurs = [
            Arrow(ORIGIN, 2*RIGHT, buff=0, color=RED),
            Arrow(ORIGIN, 2*RIGHT, buff=0, color=GREEN),
            Arrow(ORIGIN, 2*RIGHT, buff=0, color=BLUE)
        ]
        vecteurs = VGroup(*vecteurs)

        self.play(*[GrowArrow(v) for v in vecteurs])

        # Animation de rotation des vecteurs
        self.play(Rotate(vecteurs[0], angle=2*PI, about_point=ORIGIN, run_time=4, rate_func=linear))
        self.play(Rotate(vecteurs[1], angle=2*PI, about_point=ORIGIN, run_time=4, rate_func=linear))
        self.play(Rotate(vecteurs[2], angle=2*PI, about_point=ORIGIN, run_time=4, rate_func=linear))
        self.wait(2)
