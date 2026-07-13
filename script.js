document
  .querySelector("form")
  .addEventListener("submit", async function (event) {
    event.preventDefault();

    // Captura o valor digitado no input de e-mail
    const emailInput = document.querySelector('input[type="email"]').value;

    try {
      // Dispara a requisição POST para a sua API
      const response = await fetch("http://localhost:3000/api/newsletter", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ email: emailInput }),
      });

      if (response.ok) {
        alert("E-mail cadastrado com sucesso no banco de dados!");
        // Aqui você pode limpar o input após o sucesso
        document.querySelector('input[type="email"]').value = "";
      } else {
        alert("Ops! Ocorreu um erro ao cadastrar o e-mail.");
      }
    } catch (error) {
      console.error("Erro de conexão com a API:", error);
      alert("Erro ao conectar com o servidor.");
    }
  });
