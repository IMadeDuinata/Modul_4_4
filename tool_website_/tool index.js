// Data pelajaran
const lessons = [
  {
    id: 1,
    title: "Membaca Efektif",
    question: "Apa tujuan utama teknik skimming?",
    choices: [
      "Menemukan detail spesifik",
      "Mendapatkan gambaran umum",
      "Menghafal kata sulit",
      "Menerjemahkan kalimat"
    ],
    answerIndex: 1
  },
  {
    id: 2,
    title: "Menulis Ringkasan",
    question: "Apa langkah pertama dalam metode Cornell?",
    choices: [
      "Membagi halaman menjadi bagian",
      "Menulis kesimpulan",
      "Menyorot kalimat penting",
      "Membaca teks dua kali"
    ],
    answerIndex: 0
  }
];

let user = null;
let currentLesson = null;
let selectedChoice = null;

function login() {
  const email = document.getElementById("email").value;
  if (!email.includes("@")) return alert("Masukkan email valid!");
  user = {
    email,
    xp: 0,
    streak: 1
  };
  localStorage.setItem("user", JSON.stringify(user));
  showDashboard();
}

function logout() {
  localStorage.removeItem("user");
  location.reload();
}

function showDashboard() {
  document.getElementById("login-section").classList.add("hidden");
  document.getElementById("dashboard").classList.remove("hidden");

  document.getElementById("user-email").innerText = user.email;
  document.getElementById("xp").innerText = user.xp;
  document.getElementById("streak").innerText = user.streak;

  const container = document.getElementById("lesson-list");
  container.innerHTML = "";
  lessons.forEach(lesson => {
    const div = document.createElement("div");
    div.className = "lesson-item";
    div.innerText = lesson.title;
    div.onclick = () => startLesson(lesson.id);
    container.appendChild(div);
  });
}

function startLesson(id) {
  currentLesson = lessons.find(l => l.id === id) || lessons[0];
  document.getElementById("dashboard").classList.add("hidden");
  document.getElementById("lesson-section").classList.remove("hidden");

  document.getElementById("lesson-title").innerText = currentLesson.title;
  document.getElementById("lesson-question").innerText = currentLesson.question;

  const choiceContainer = document.getElementById("choices");
  choiceContainer.innerHTML = "";
  currentLesson.choices.forEach((c, i) => {
    const btn = document.createElement("button");
    btn.innerText = c;
    btn.onclick = () => {
      selectedChoice = i;
      document.querySelectorAll("#choices button").forEach(b => b.classList.remove("selected"));
      btn.classList.add("selected");
    };
    choiceContainer.appendChild(btn);
  });
}

function submitAnswer() {
  if (selectedChoice === null) return alert("Pilih jawaban dulu!");

  const feedback = document.getElementById("feedback");
  if (selectedChoice === currentLesson.answerIndex) {
    feedback.innerText = "✅ Benar! +10 XP";
    user.xp += 10;
    localStorage.setItem("user", JSON.stringify(user));
  } else {
    feedback.innerText = "❌ Salah, coba lagi!";
  }

  setTimeout(() => {
    feedback.innerText = "";
    document.getElementById("lesson-section").classList.add("hidden");
    document.getElementById("dashboard").classList.remove("hidden");
    showDashboard();
  }, 1500);
}

// Auto-login jika user sudah ada
window.onload = () => {
  const saved = localStorage.getItem("user");
  if (saved) {
    user = JSON.parse(saved);
    showDashboard();
  }
};
