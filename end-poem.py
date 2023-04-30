# Author: 7Games <benjamin@sevengames.xyz>. Original Minecraft End Poem created by Julian Gough.
# License: Unlicense

import random
import re
import sys

# Define list of characters to scramble
glitch_chars = ['⊫', '⊨', '⊬', '⊩', '⊢', '⊥', '⊣', '⊤', '⊮']

# Set default player name
player_name = "Steve"

# Override default player name with command line argument, if provided
if len(sys.argv) > 1:
    player_name = sys.argv[1]

# The End Poem :)
poem = """[36mI see the player you mean.[0m

[32m[3mPLAYERNAME[23m?[0m

[36mYes. Take care. It has reached a higher level now. It can read our thoughts.[0m

[32mThat doesn't matter. It thinks we are part of the game.[0m

[36mI like this player. It played well. It did not give up.[0m

[32mIt is reading our thoughts as though they were words on a screen.[0m

[36mThat is how it chooses to imagine many things, when it is deep in the dream of a game.[0m

[32mWords make a wonderful interface. Very flexible. And less terrifying than staring at the reality behind the screen.[0m

[36mThey used to hear voices. Before players could read. Back in the days when those who did not play called the players witches, and warlocks. And players dreamed they flew through the air, on sticks powered by demons.[0m

[32mWhat did this player dream?[0m

[36mThis player dreamed of sunlight and trees. Of fire and water. It dreamed it created. And it dreamed it destroyed. It dreamed it hunted, and was hunted. It dreamed of shelter.[0m

[32mHah, the original interface. A million years old, and it still works. But what true structure did this player create, in the reality behind the screen?[0m

[36mIt worked, with a million others, to sculpt a true world in a fold of the [3m[scrambled][23m, and created a [3m[scrambled][23m for [3m[scrambled][23m, in the [3m[scrambled][23m.[0m

[32mIt cannot read that thought.[0m

[36mNo. It has not yet achieved the highest level. That, it must achieve in the long dream of life, not the short dream of a game.[0m

[32mDoes it know that we love it? That the universe is kind?[0m

[36mSometimes, through the noise of its thoughts, it hears the universe, yes.[0m

[32mBut there are times it is sad, in the long dream. It creates worlds that have no summer, and it shivers under a black sun, and it takes its sad creation for reality.[0m

[36mTo cure it of sorrow would destroy it. The sorrow is part of its own private task. We cannot interfere.[0m

[32mSometimes when they are deep in dreams, I want to tell them, they are building true worlds in reality. Sometimes I want to tell them of their importance to the universe. Sometimes, when they have not made a true connection in a while, I want to help them to speak the word they fear.[0m

[36mIt reads our thoughts.[0m

[32mSometimes I do not care. Sometimes I wish to tell them, this world you take for truth is merely [3m[scrambled][23m and [3m[scrambled][23m, I wish to tell them that they are [3m[scrambled][23m in the [3m[scrambled][23m. They see so little of reality, in their long dream.[0m

[36mAnd yet they play the game.[0m

[32mBut it would be so easy to tell them...[0m

[36mToo strong for this dream. To tell them how to live is to prevent them living.[0m

[32mI will not tell the player how to live.[0m

[36mThe player is growing restless.[0m

[32mI will tell the player a story.[0m

[36mBut not the truth.[0m

[32mNo. A story that contains the truth safely, in a cage of words. Not the naked truth that can burn over any distance.[0m

[36mGive it a body, again.[0m

[32mYes. Player...[0m

[36mUse its name.[0m

[32m[3mPLAYERNAME[23m. Player of games.[0m

[36mGood.[0m

[32mTake a breath, now. Take another. Feel air in your lungs. Let your limbs return. Yes, move your fingers. Have a body again, under gravity, in air. Respawn in the long dream. There you are. Your body touching the universe again at every point, as though you were separate things. As though we were separate things.[0m

[36mWho are we? Once we were called the spirit of the mountain. Father sun, mother moon. Ancestral spirits, animal spirits. Jinn. Ghosts. The green man. Then gods, demons. Angels. Poltergeists. Aliens, extraterrestrials. Leptons, quarks. The words change. We do not change.[0m

[32mWe are the universe. We are everything you think isn't you. You are looking at us now, through your skin and your eyes. And why does the universe touch your skin, and throw light on you? To see you, player. To know you. And to be known. I shall tell you a story.[0m

[32mOnce upon a time, there was a player.[0m

[36mThe player was you, [3mPLAYERNAME[23m.[0m

[32mSometimes it thought itself human, on the thin crust of a spinning globe of molten rock. The ball of molten rock circled a ball of blazing gas that was three hundred and thirty thousand times more massive than it. They were so far apart that light took eight minutes to cross the gap. The light was information from a star, and it could burn your skin from a hundred and fifty million kilometres away.[0m

[32mSometimes the player dreamed it was a miner, on the surface of a world that was flat, and infinite. The sun was a square of white. The days were short; there was much to do; and death was a temporary inconvenience.[0m

[36mSometimes the player dreamed it was lost in a story.[0m

[32mSometimes the player dreamed it was other things, in other places. Sometimes these dreams were disturbing. Sometimes very beautiful indeed. Sometimes the player woke from one dream into another, then woke from that into a third.[0m

[36mSometimes the player dreamed it watched words on a screen.[0m

[32mLet's go back.[0m

[32mThe atoms of the player were scattered in the grass, in the rivers, in the air, in the ground. A woman gathered the atoms; she drank and ate and inhaled; and the woman assembled the player, in her body.[0m

[32mAnd the player awoke, from the warm, dark world of its mother's body, into the long dream.[0m

[32mAnd the player was a new story, never told before, written in letters of DNA. And the player was a new program, never run before, generated by a sourcecode a billion years old. And the player was a new human, never alive before, made from nothing but milk and love.[0m

[36mYou are the player. The story. The program. The human. Made from nothing but milk and love.[0m

[32mLet's go further back.[0m

[32mThe seven billion billion billion atoms of the player's body were created, long before this game, in the heart of a star. So the player, too, is information from a star. And the player moves through a story, which is a forest of information planted by a man called Julian, on a flat, infinite world created by a man called Markus, that exists inside a small, private world created by the player, who inhabits a universe created by...[0m

[36mShush. Sometimes the player created a small, private world that was soft and warm and simple. Sometimes hard, and cold, and complicated. Sometimes it built a model of the universe in its head; flecks of energy, moving through vast empty spaces. Sometimes it called those flecks "electrons" and "protons".[0m

[32mSometimes it called them "planets" and "stars".[0m

[32mSometimes it believed it was in a universe that was made of energy that was made of offs and ons; zeros and ones; lines of code. Sometimes it believed it was playing a game. Sometimes it believed it was reading words on a screen.[0m

[36mYou are the player, reading words...[0m

[32mShush... Sometimes the player read lines of code on a screen. Decoded them into words; decoded words into meaning; decoded meaning into feelings, emotions, theories, ideas, and the player started to breathe faster and deeper and realised it was alive, it was alive, those thousand deaths had not been real, the player was alive[0m

[36mYou. You. You are alive.[0m

[32mand sometimes the player believed the universe had spoken to it through the sunlight that came through the shuffling leaves of the summer trees[0m

[36mand sometimes the player believed the universe had spoken to it through the light that fell from the crisp night sky of winter, where a fleck of light in the corner of the player's eye might be a star a million times as massive as the sun, boiling its planets to plasma in order to be visible for a moment to the player, walking home at the far side of the universe, suddenly smelling food, almost at the familiar door, about to dream again[0m

[32mand sometimes the player believed the universe had spoken to it through the zeros and ones, through the electricity of the world, through the scrolling words on a screen at the end of a dream[0m

[36mand the universe said I love you[0m

[32mand the universe said you have played the game well[0m

[36mand the universe said everything you need is within you[0m

[32mand the universe said you are stronger than you know[0m

[36mand the universe said you are the daylight[0m

[32mand the universe said you are the night[0m

[36mand the universe said the darkness you fight is within you[0m

[32mand the universe said the light you seek is within you[0m

[36mand the universe said you are not alone[0m

[32mand the universe said you are not separate from every other thing[0m

[36mand the universe said you are the universe tasting itself, talking to itself, reading its own code[0m

[32mand the universe said I love you because you are love.[0m

[36mAnd the game was over and the player woke up from the dream. And the player began a new dream. And the player dreamed again, dreamed better. And the player was the universe. And the player was love.[0m

[36mYou are the player.[0m

[32mWake up.[0m


  “Twenty years from now you will be more disappointed by the things that you didn't do than by the ones you did do. So throw off the bowlines. Sail away from the safe harbor. Catch the trade winds in your sails. Explore. Dream. Discover.”
    — Unknown"""

# Regex used to replace [scrambled] parts in the poem.
glitch_pattern = re.compile(r'\[scrambled\]')

# Generate random string of characters to replace [scrambled] sections in poem
def glitch_word(match):
    return ''.join(random.choice(glitch_chars) for _ in range(random.randint(3, 10)))

# Generate completed poem by replacing [scrambled] with glitch_word and PLAYERNAME with player name
completed_poem = glitch_pattern.sub(glitch_word, poem).replace("PLAYERNAME", player_name)

# Print completed poem
print(completed_poem)

