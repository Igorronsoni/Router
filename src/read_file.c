#include "../include/read_file.h"

// Realiza a leitura do arquivo enlases para descobrir os vizinhos do roteador atual
void read_enlaces()
{
  FILE *arq = fopen("../configs/enlaces.config", "r");

  int router1, router2, cost;
  while (!feof(arq))
  {
    fscanf(arq, "%d %d %d", &router1, &router2, &cost);
    if (main_router.id == router1)
    {
      if (indexOf(router2) != -1)
        continue;
      vizinhos[(vizinhos_contador++)] = router2;
    }
    if (main_router.id == router2)
    {
      if (indexOf(router1) != -1)
        continue;
      vizinhos[(vizinhos_contador++)] = router2;
    }
  }
  fclose(arq);
}

// Busca dados dos vizinhos
bool read_routers()
{
  FILE *arq = fopen("../configs/roteador.config", "rt");

  while (!feof(arq))
  {
    Roteador router;
    fscanf(arq, "%d %hu %s", &router.id, &router.port, router.ip);
    if (router.id == main_router.id)
    {
      main_router.port = router.port;
      memcpy(main_router.ip, router.ip, sizeof(router.ip));
    }
    if (indexOf(router.id) != -1)
    {
      router_vizinho[(router_vizinho_contador++)] = router;
    }
  }
  fclose(arq);
  if (main_router.port != 0)
  {
    return true;
  }
  else
    return false;
}
