<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Birthday Surprise Ultra</title>
<style>
    body {
        margin: 0;
        background-color: #000;
        font-family: monospace;
        overflow: hidden;
        text-align: center;
    }
    #message {
        font-size: 20px;
        font-weight: bold;
        margin-top: 20px;
    }
    .cake {
        font-size: 20px;
        line-height: 1.2;
        white-space: pre;
        margin-top: 30px;
        transition: color 0.3s, transform 0.3s;
    }
    .firework {
        position: absolute;
        font-size: 20px;
        pointer-events: none;
        user-select: none;
    }
    .confetti {
        position: absolute;
        font-size: 16px;
        pointer-events: none;
        user-select: none;
    }
</style>
</head>
<body>

<div id="message"></div>

<pre class="cake" id="cake">
        i i i i i i i
       | | | | | | | |
      *****************
     *     HAPPY      *
    *     BIRTHDAY    *
   *********************
   *        BRO        *
   *********************
</pre>

<script>
const colors = ["#FF0000", "#00FF00", "#FFFF00", "#00FFFF", "#FF00FF", "#FFA500", "#FFFFFF"];
const cake = document.getElementById('cake');
const message = document.getElementById('message');

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

// Typing message function
async function typeMessage(msg) {
    message.innerHTML = '';
    for(let char of msg) {
        message.innerHTML += `<span style="color:${colors[Math.floor(Math.random()*colors.length)]}">${char}</span>`;
        await sleep(50);
    }
}

// Cake pulsating/blinking
function blinkCake() {
    let scale = 1;
    setInterval(() => {
        cake.style.color = colors[Math.floor(Math.random()*colors.length)];
        scale = scale === 1 ? 1.05 : 1;
        cake.style.transform = `scale(${scale})`;
    }, 300);
}

// Fireworks animation
async function fireworks() {
    const totalFireworks = 25;
    for(let i=0; i<totalFireworks; i++) {
        let x = Math.random() * window.innerWidth;
        let y = Math.random() * window.innerHeight/2;
        let particles = 6 + Math.floor(Math.random() * 6);
        for(let j=0; j<particles; j++) {
            const star = document.createElement('div');
            star.className = 'firework';
            star.style.color = colors[Math.floor(Math.random()*colors.length)];
            star.style.left = `${x + Math.random()*50 - 25}px`;
            star.style.top = `${y + Math.random()*50 - 25}px`;
            star.innerHTML = "*";
            document.body.appendChild(star);
            setTimeout(()=>{star.remove();}, 1000);
        }
        await sleep(300);
    }
}

// Confetti animation
function confettiFall() {
    const symbols = ["*", "•", "❉", "✦", "✺"];
    setInterval(() => {
        const confetti = document.createElement('div');
        confetti.className = 'confetti';
        confetti.style.color = colors[Math.floor(Math.random()*colors.length)];
        confetti.style.left = `${Math.random()*window.innerWidth}px`;
        confetti.style.top = `-20px`;
        confetti.innerHTML = symbols[Math.floor(Math.random()*symbols.length)];
        document.body.appendChild(confetti);

        let top = -20;
        const fall = setInterval(() => {
            top += 4 + Math.random()*2;
            confetti.style.top = `${top}px`;
            if(top > window.innerHeight) {
                confetti.remove();
                clearInterval(fall);
            }
        }, 50);
    }, 100);
}

// Main function
async function main() {
    await typeMessage("Hey little brother, a birthday gift for you! Happy Birthday Bro!");
    blinkCake();       // cake blinking/pulsating
    confettiFall();    // start confetti
    await fireworks(); // fireworks animation
}

main();
</script>

</body>
</html>
