<?php
$hasil = "";
if(isset($_POST['submit'])){
    $jawaban = $_POST['q1'];
    if($jawaban == "Hello"){
        $hasil = "Benar! 🎉";
    } else {
        $hasil = "Salah, coba lagi 😅";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Quiz - English</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<header>
    <h2>Quiz Bahasa Inggris</h2>
    <nav>
        <a href="index.php">Home</a>
        <a href="lesson.php">Lessons</a>
        <a href="quiz.php">Quiz</a>
    </nav>
</header>

<section>
    <h1>Soal Quiz</h1>
    <form method="post">
        <p>Apa Bahasa Inggris dari "Halo" ?</p>

        <input type="radio" name="q1" value="Hello"> Hello <br>
        <input type="radio" name="q1" value="Thanks"> Thanks <br>
        <input type="radio" name="q1" value="Goodbye"> Goodbye <br><br>

        <button type="submit" name="submit" class="btn">Kirim Jawaban</button>
    </form>

    <h3><?php echo $hasil; ?></h3>
</section>

</body>
</html>
